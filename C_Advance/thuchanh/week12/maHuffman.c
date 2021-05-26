#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLength 256 

typedef struct Node{ 
	
	int weight;//Trong so
	
	char ch; // Neu la not la (leaf) thi se chua ky hieu
	struct Node* Next; //pointer to next element
	struct Node *left, * right;

} Node;

typedef Node* Position; 
typedef struct{ 
	Position Front, Rear;
	int counter;//counter dung de luu So phan tu hien co trong queue
} Queue;

typedef struct {
	int size;
	char bits[20];
} Coding;
Coding huffmanTable[256];

void MakeNullQueue(Queue *Q){ 
	
	Q->counter = 0;
	Q->Front = Q->Rear = NULL;
}

int Empty_Queue(Queue Q){ 
	return (Q.Front == NULL && Q.Rear == NULL); 
} 

// Them mot nut moi vao danh sach da sap xep
void EnQueue(Node *tmp, Queue *Q){ 
	
	if (Q->Front == NULL) { //Ban dau, danh sach rong
							// Them node moi vao, de con tro Front va Rear tro den node nay
		Q->Front = Q->Rear = tmp;
		Q->counter++;
	}
	else {
			//Duyet Queue tu dau ve cuoi
			Position cur; // cur tro toi node hien tai dang duoc xem xet trong qua trinh duyet danh sach
			Position prev;// prev tro toi node dung truoc cur
			prev = Q->Front;
			cur = prev->Next;
			
			int found = 0;
			while (cur != NULL && cur->weight <= tmp->weight)  {
				prev = cur;
				cur = cur->Next;
				 found = 1;
			}
			if (cur == NULL) { // Neu duyet toi cuoi danh sach
				

				if ((found == 0) && (prev->weight > tmp->weight) ) { //Truong hop danh sach chi co 1 node
					              // Node moi duoc them vao phia truoc cua node da co
					tmp->Next = prev;
					Q->Front = tmp;
					Q->counter++;
				}
				else {	   	
					Q->Rear->Next = tmp; // Them node moi vao cuoi danh sach
 					Q->Rear = tmp; // Q->Rear tro toi nut cuoi danh sach 
 					Q->counter++;
				}
			}
			else { //Chen vao giua danh sach
				prev->Next = tmp;
				tmp->Next = cur;
				Q->counter++;
			}
	}
}

Node * DeQueue(Queue *Q){ 
	if (!Empty_Queue(*Q)){ 
		Position T; 
		T = Q->Front; 
		
		Q->Front = Q->Front->Next; 
		Q->counter--;
		
		return T;
	} 
	else {
		return NULL;
	} 
} 

void PrintQueue (Queue Q) {
	
	Position cur;
	printf("Queue hien tai:\n");
	for (cur = Q.Front; cur != NULL; cur = cur->Next)
			printf(" %d %c ",cur->weight,cur->ch);
	printf("\n");
}

void createHuffmanCode (Node *tree, Coding code) {
	if (tree->ch != '\0') {
		huffmanTable[tree->ch] = code;
		//code.bits[code.size] ='\0';
		printf("Ky tu %c co Huffman code la:%s\n",tree->ch,code.bits);
		
	}
	Coding inputted_code = code;
	if (tree->left != NULL) {
		code.bits[code.size++] = '0';

		createHuffmanCode (tree->left,code);
	}
	code  = inputted_code;
	if (tree->right != NULL) {
		code.bits[code.size++] = '1';

		createHuffmanCode (tree->right,code);
	}


}

void makeHuffman(char *buffer,int size) {
		Queue NodeQueue;
		MakeNullQueue(&NodeQueue);
		unsigned int ch;
		int i,Freq[256];
		// Khoi tao mang chua tan suat xuat hien cua cac ki tu
		for (i = 0; i < 256;i++) Freq[i] = 0;
		//Tinh tan suat xuat hien
		for (i = 0 ; i < size;i++) 
			{
				ch = buffer[i];
				Freq[ch]++;
			}

		//Them vao hang doi
		for (i = 0 ; i < MaxLength;i++) 
			if (Freq[i] > 0) {
					
					Node *tmp = (Node *)malloc(sizeof(Node));
					tmp->weight = Freq[i];
					tmp->ch = i;
					tmp->left = tmp->right = tmp->Next = NULL;
					EnQueue(tmp,&NodeQueue);
					
			}
		
		PrintQueue(NodeQueue);
		Node *n1 = NULL,*n2 = NULL;
		
		for (;;) {
			// Lan luot lay 2 nut ra khoi danh sach
			if (NodeQueue.counter > 1) {
				n1 = DeQueue(&NodeQueue);
			
				n2 = DeQueue(&NodeQueue);
				
				    Node  *tmp = (Node *)malloc(sizeof(Node));;
					tmp->weight = n1->weight + n2->weight;
					tmp->ch = '\0';
					tmp->left = n1;
					tmp->right = n2;
					tmp->Next = NULL;
					EnQueue(tmp,&NodeQueue);
	 				PrintQueue(NodeQueue);
			}
			else {
					//Chi con 1 node trong queue
					break;
			}
			
		}
		n1 = DeQueue(&NodeQueue);
		//Make Huffman Coding Table
		Coding code;
		code.size = 0;
		createHuffmanCode(n1,code);
}

void setBit(char* huffman, int nbit, int val) {
	int i, byte, bit;
	byte = nbit/8;
	bit = nbit%8;
	if (val==0) {
		huffman[byte] &= ~(1 << bit);
	} else {
		huffman[byte] |= (1 << bit);
	}
}

int getBit(char* huffman, int nbit) {
	int i, byte, bit;
	byte = nbit/8;
	bit = nbit%8;
	i =	huffman[byte] & (1 << bit);
	return i!=0;
}

void addHuffmanChar(char ch, Coding htable[], char* huffman, int* nbit) {
	int i;
	for (i=0; i<htable[ch].size; i++) {
		setBit(huffman, *nbit, htable[ch].bits[i]);
		(*nbit)++;
	}
}
// return number of bits
int compress(char* buffer, char*huffman, Coding htable[]) {
	
	
	printf("Original size: %ld bytes\n", strlen(buffer));
	printf("%s\n", buffer);
	// Compress
	int n = strlen(buffer);
	int nbit = 0;
	int i;
	for (i=0; i<n; i++)
		addHuffmanChar(buffer[i], htable, huffman, &nbit);
	printf("Compressed size: %d bytes\n", (nbit/8)+1);
	for (i=0; i<nbit; i++)
		printf("%d", getBit(huffman, i));
	printf("\n");
	return nbit;
}
int main() {
	char *text = "Eerie eyes seen near lake.";//"Doan van ban vi du ma hoa Huffman";
	makeHuffman(text,strlen(text));
	char huffman[1000];
  	 //Coding htable[256];
   	int nbit, bytes;
   	nbit = compress(text, huffman, huffmanTable);

	
	return 0;
}

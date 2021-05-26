#include<stdio.h>

void swap(int *a,int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int find(int st[9]){
    int i = 0;
    while(st[i] != 0){
        i++;
    }
    return i; //tim vi tri cua i
}

void up(int st[9],int k){
    swap(&st[k],&st[k-3]);
    //return st;
}

void down(int st[9],int k){
    swap(&st[k],&st[k+3]);
    //return st;
}

void left(int st[9],int k){
    swap(&st[k],&st[k-1]);
    //return st;
}

void right(int st[9],int k){
    swap(&st[k],&st[k+1]);
    //return st;
}
void show(int st[9]){
    printf("\n");
    printf("%d %d %d\n",st[0],st[1],st[2]);
    printf("%d %d %d\n",st[3],st[4],st[5]);
    printf("%d %d %d\n",st[6],st[7],st[8]);
}

int main(){
    int st[9];
    printf("nhap vao chuoi so ban muon :");
    int i;
    char input;
    for(i = 0;i<9;i++){
        scanf("%d",&st[i]);
    }
    do{
        show(st);
        int k;
        k = find(st);
        printf("nhap buoc di : ");
        scanf("%c",&input);
        while(getchar() != '\n');
        if(input == 'w'){
            up(st,k);
        }
        if(input == 's'){
            down(st,k);
        }
        if(input == 'a'){
            left(st,k);
        }
        if(input == 'd'){
            right(st,k);
        }
        if(input == 'q'){
            break;
        }
    }while(input != 'q');
    return 0;
}
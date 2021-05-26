#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct stated{
    int st[9];
    struct stated *next;
}stated;

stated *new(int st[9]){
    stated *temp;
    temp = (stated*)malloc(sizeof(stated));
    int i;
    for(i = 0;i<9;i++){
        temp->st[i] = st[i];
    }
    temp->next = NULL;
    return temp;
}

int find(int st[9]){
    int i = 0;
    while(st[i] != 0){
        i++;
    }
    return i; //tim vi tri cua i
}

void swap(int *a,int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int* up(int st[9],int k){
    swap(&st[k],&st[k-3]);
    return st;
}

int *down(int st[9],int k){
    swap(&st[k],&st[k+3]);
    return st;
}

int *left(int st[9],int k){
    swap(&st[k],&st[k-1]);
    return st;
}

int *right(int st[9],int k){
    swap(&st[k],&st[k+1]);
    return st;
}
stated* addstate(stated **s,int st[9]){
    if((*s) == NULL){
        (*s) = new(st);
    }
    else{
        while(((*s)->next) != NULL){
            (*s) = (*s)->next;
        }
        (*s)->next = new(st);
    }
    return *s;
}
int p(stated *s,stated *p){
    while(p->next != NULL){
        if(test(s->st,p->st) == 9)
        {
            return 1;
        }
    }
    return 0;
}
stated *Tfirst(stated **s){
    stated *temp;
    temp = new((*s)->st);
    return temp;
}
stated *Dfirst(stated **s){
    (*s) = (*s)->next;
    return *s;
}

int test(int st[9],int s[9]){
    int i;
    int count = 0;
    for(i=0;i<9;i++){
        if(st[i] == s[i]){
            count++;
        }
    }
    return count;
}

void show(int st[9]){
    printf("%d %d %d\n",st[0],st[1],st[2]);
    printf("%d %d %d\n",st[3],st[4],st[5]);
    printf("%d %d %d\n",st[6],st[7],st[8]);
}

int main(){
    int st[9] = {1,2,3,4,5,6,7,8,0};
    int ss[9] = {1,2,3,4,0,5,7,8,6};
    stated *open;
    stated *close;
    stated *temp;
    open = temp = new(st);
    while(test(temp->st,ss) != 9){
        int k;
        close = addstate(&close,temp->st);
        k = find(open->st);
        if(k==0){
            open = addstate(&open,down(open->st,k));
            open = addstate(&open,right(open->st,k));
        }
        if(k==1){
            open = addstate(&open,down(open->st,k));
            open = addstate(&open,right(open->st,k));
            open = addstate(&open,left(open->st,k));
        }
        if(k==2){
            open = addstate(&open,down(open->st,k));
            open = addstate(&open,left(open->st,k));
        }
        if(k==3){
            open = addstate(&open,down(open->st,k));
            open = addstate(&open,right(open->st,k));
            open = addstate(&open,up(open->st,k));
        }
        if(k==4){
            open = addstate(&open,down(open->st,k));
            open = addstate(&open,up(open->st,k));
            open = addstate(&open,left(open->st,k));
            open = addstate(&open,right(open->st,k));
        }
        if(k==5){
            open = addstate(&open,down(open->st,k));
            open = addstate(&open,up(open->st,k));
            open = addstate(&open,left(open->st,k));
        }
        if(k==6){
            open = addstate(&open,up(open->st,k));
            open = addstate(&open,right(open->st,k));
        }
        if(k=7){
            open = addstate(&open,up(open->st,k));
            open = addstate(&open,right(open->st,k));
           open =  addstate(&open,left(open->st,k));
        }
        if(k==8){
            open = addstate(&open,up(open->st,k));
            open = addstate(&open,left(open->st,k));
        }
        close = addstate(&close,temp->st);
        temp = Tfirst(&open);
        open = Dfirst(&open);
        while(p(temp,close) != 1){
            temp = Tfirst(&open);
            open = Dfirst(&open);
        }
    }
    while(close->next != NULL){
        show(close->st);
        close = close->next;
    }
    show(temp->st);
    return 0;
}



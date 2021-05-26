#include<stdio.h>
void swap(int *a,int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
int main(){
    int a = 1,b=2,c;
    swap(&a,&b);
    printf("a = %d,b = %d\n",a,b);
    return 0;
}
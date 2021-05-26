# include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"jrb.h"
#include"dllist.h"

typedef JRB Graph;
typedef struct {
    Graph graph;
    JRB root;
}HuffmanTree;
typedef struct {
    int count;
    int p;
}chars;
void make(char *buffer){
    chars s[256];
    int i,j,k;
    for (i = 0;i<256;i++){
        s[i].p = i;
        s[i].count = 0;
    }
    for(j=0;j<strlen(buffer);j++)
    {
        if(buffer[j]>=0 && buffer[j] < 256){
            s[buffer[j]].count ++;
        }
    }
    /*for(k = 0;k<256;k++)
    {
        if(s[i].count != 0){
            printf("%s : %d\n",s[i].p,s[i].count);
        }
    }*/
}

typedef struct{
    int size;
    char bit[20];
}Coding;
Coding HuffmanTable[256];





int main(){
    char *s;
    printf("nhap chuoi : ");
    scanf("%s",s);
    //HuffmanTree makke;
    make(s);
    return 0;

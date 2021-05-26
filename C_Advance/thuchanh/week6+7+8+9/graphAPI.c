#include<stdio.h>
#include<stdlib.h>
typedef struct graph{
    int *matrix;
    int maxsize;
}graph;
graph creat(int maxsize){
    graph temp;
    temp.matrix = (int*)malloc(maxsize*maxsize*sizeof(int));
    int i;
    for(i =0;i<maxsize*maxsize;i++){
        temp.matrix[i] = 0;
    }
    temp.maxsize = maxsize;
    return temp;
}
void addgraph(graph g,int v1,int v2){
    g.matrix[v1*g.maxsize + v2] = 1;
    g.matrix[v2*g.maxsize + v1] = 1;
}
int adjacent(graph g,int v1,int v2){
    if(g.matrix[v1*g.maxsize + v2] == 1) return 1;
    else return 0;
}
int get(graph g,int v1,int output[100]){
    int n = 0;
    int i,k;
    for(i = 0;i<g.maxsize;i++){
        k=adjacent(g,v1,output[i]);
        if(k==1){
            n++;
            printf("co lien ket voi %d\n",output[i]);
        }
    }
    return n;
}
//void drop(graph g){
  //  free(g.matrix);
   // free(g);
//}
void in(graph g){
    int i,j;
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            printf("%d ",g.matrix[i*100 + j]);
        }
        printf("\n");
    }
}
int main(){
    int i,n;
    int output[100];
    for(i = 0;i<100;i++){
        output[i] = i;
    }
    graph g;
    g = creat(100);
    addgraph(g,0,1);
    addgraph(g,1,2);
    addgraph(g,3,4);
    addgraph(g,0,2);
    n = get(g,0,output);
    if(n==0){
        printf("ko co lien ke voi nut 0\n");
    }
    in(g);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include"C:\Users\Administrator\Desktop\myC\C_Advance\thuchanh\week6+7\jrb.h"
typedef JRB graph;
graph create(){
    graph g;
    g = make_jrb();
    return g;
}
void addgraph(graph g,int v1,int v2){
    graph tree;
    if(jrb_find_int(g,v1) == NULL )
    {
        
        tree = make_jrb();
        jrb_insert_int(g,v1,new_jval_v(tree));
        jrb_insert_int(g,v2,new_jval_i(1));
    }
    else{
        graph node;
        node = jrb_find_int(g,v1);
        tree = (JRB)jval_v(node->val);
        jrb_insert_int(tree,v2,new_jval_i(1));   
    }
}
int adjacent(graph g,int v,int output[100]){
    graph node,tree;
    node = jrb_find_int(g,v);
    tree = (JRB)jval_v(node->val);
    int total = 0;
    jrb_traverse(node,tree)
        output[total++] =jval_i(node->key);
    return total;
}
int main(){
    int i,n;
    int output[100];
    for (i = 0;i<100;i++){
        output[i] = i;
    }
    graph g;
    g = create(g);
    addgraph(g,0,1);
    addgraph(g,0,2);
    addgraph(g,0,3);
    n = adjacent(g,0,output);
    if(n==0) printf("ko co duong noi vs nut 0\n");
    else{
        printf("co duong den nut 0\n");
        for(i=0;i<100;i++){
            printf("%5d\n",output[i]);
        }
    }
    return 0;
}
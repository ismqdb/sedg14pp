#include "./node.h"

node* n_alloc(){
    return (node*)malloc(sizeof(node*));
}

node* nalloc_i(int value){
    node *n = (node*)malloc(sizeof(node*));
    n->key = value;
    return n;
}

void n_dealloc(node *node){
    if(node != NULL)
        free(node);
}
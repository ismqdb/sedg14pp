#include "./node.h"

node* node_alloc(){
    return (node*)malloc(sizeof(node*));
}

node* node_alloc_int(int value){
    node *n = (node*)malloc(sizeof(node*));
    n->key = value;
    return n;
}

void node_dealloc(node *node){
    if(node != NULL)
        free(node);
}
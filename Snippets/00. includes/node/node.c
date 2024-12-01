/* ******************************************************************************** */

#include "./node.h"

/* ******************************************************************************** */

struct node* nodeAlloc(){
    return (struct node*)malloc(sizeof(struct node*));
}

/* ******************************************************************************** */

struct node* nodeAllocInt(int value){
    struct node *n = (struct node*)malloc(sizeof(struct node*));
    n->key = value;
    return n;
}

/* ******************************************************************************** */

void nodeDealloc(struct node *node){
    if(node != NULL)
        free(node);
}

/* ******************************************************************************** */
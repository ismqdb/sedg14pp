#pragma once

#include <stdio.h>

typedef struct node {
    int key;
    struct node *next;
} node;

node* n_alloc(){
    return (node*)malloc(sizeof(node));
}

void n_dealloc(node *node){
    if(node != NULL)
        free(node);
}
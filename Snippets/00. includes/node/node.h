#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *next;
} node;

node* n_alloc();
node* nalloc_i(int);
void n_dealloc(node*);
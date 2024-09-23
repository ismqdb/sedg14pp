#pragma once

#include <stdio.h>

typedef struct node_f {
    char info;
    struct node_f *child;
    struct node_f *sibling;
} node_f;

node_f n_f_init(char);
void visit_f(node_f*);
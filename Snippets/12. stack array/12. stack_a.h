#pragma once

#include <stdlib.h>

#include "../00. Includes/tree node/tree_node.h"

typedef struct stack_a {
    data_type type;
    union {
        int* integer;
        tree_node** t_node;
    } data;
    int p;
    int current_size;
    int chunk_size;
} stack_a;

void push_int(stack_a*, int);
void push_t_node(stack_a*, tree_node*);
int pop_int(stack_a*);
tree_node* pop_t_node(stack_a*);
stack_a stack_init(data_type, int);
void stack_deinit(stack_a);
int is_empty(stack_a);
#pragma once

#include <stdlib.h>

#include "../00. includes/tree_node_data_type.h"
#include "../00. includes/tree node/tree_node.h"

typedef struct stack_a {
    data_type type;
    union {
        int* integer;
        tree_node** tree_node;
    } data;
    int p;
    int current_size;
    int chunk_size;
} stack_a;

void stack_a_push_int(stack_a*, int);
void stack_a_push_tree_node(stack_a*, tree_node*);
int stack_a_pop_int(stack_a*);
tree_node* stack_a_pop_tree_node(stack_a*);
stack_a stack_a_init(data_type, int);
void stack_a_deinit(stack_a*);
int stack_a_is_empty(stack_a*);
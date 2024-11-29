/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdlib.h>

/* ******************************************************************************** */

#include "../00. includes/treeNodeDataType.h"
#include "../00. includes/tree node/tree_node.h"

/* ******************************************************************************** */

typedef struct stack_a {
    treeNodeDataType type;
    union {
        int* integer;
        struct tree_node** tree_node;
    } data;
    int p;
    int current_size;
    int chunk_size;
} stack_a;

/* ******************************************************************************** */

void stack_a_push_int(stack_a*, int);
void stack_a_push_tree_node(stack_a*, struct tree_node*);
int stack_a_pop_int(stack_a*);
struct tree_node* stack_a_pop_tree_node(stack_a*);
stack_a stack_a_init(treeNodeDataType, int);
void stack_a_deinit(stack_a*);
int stack_a_is_empty(stack_a*);

int stack_a_size(stack_a*);

/* ******************************************************************************** */
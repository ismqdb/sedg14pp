#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node {
    char info;
    struct tree_node* left;
    struct tree_node* right;
} tree_node;

tree_node* tree_node_init();
tree_node* tree_node_init_char(char);
void tree_node_deinit(tree_node*);
void tree_node_visit(tree_node*);
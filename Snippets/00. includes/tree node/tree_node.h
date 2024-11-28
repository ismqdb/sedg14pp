/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/* ******************************************************************************** */

#include "../parse tree/parse_tree.h"

/* ******************************************************************************** */

typedef struct tree_node {
    char info;
    struct tree_node* left;
    struct tree_node* right;
} tree_node;

/* ******************************************************************************** */

struct tnode_pair {
    struct tree_node *node;
    int index;
};

/* ******************************************************************************** */

tree_node* tree_node_init();
tree_node* tree_node_init_char(char);
void tree_node_deinit(tree_node*);
void tree_node_visit(tree_node*);

/* ******************************************************************************** */

int draw_binary_tree_recursive(tree_node*, struct tnode_pair**, int, int);
void external_path_length(tree_node*, int, int*);
int draw_binary_tree_recursive_driver();
void visit_tree_node(tree_node);

/* ******************************************************************************** */
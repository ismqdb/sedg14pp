#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "../parse tree/parse_tree.h"

typedef struct tree_node {
    char info;
    struct tree_node* left;
    struct tree_node* right;
} tree_node;

struct tnode_pair {
    struct tree_node *node;
    int index;
};

tree_node* tree_node_init();
tree_node* tree_node_init_char(char);
void tree_node_deinit(tree_node*);
void tree_node_visit(tree_node*);


void drawBinaryTreeRecursive(tree_node*, struct tnode_pair**, int, int);
void externalPathLength(tree_node*, int, int*);
int drawBinaryTreeRecursiveDriver();
void visit(tree_node);
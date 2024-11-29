/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/* ******************************************************************************** */

#include "../parse tree/parse_tree.h"

/* ******************************************************************************** */

typedef struct treeNode {
    char info;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

/* ******************************************************************************** */

struct tnodePair {
    struct treeNode *node;
    int index;
};

/* ******************************************************************************** */

treeNode* tree_node_init();
treeNode* tree_node_init_char(char);

void tree_node_deinit(treeNode*);
void tree_node_visit(treeNode*);

/* ******************************************************************************** */

int draw_binary_tree_recursive(treeNode*, struct tnodePair**, int, int);
void external_path_length(treeNode*, int, int*);
int draw_binary_tree_recursive_driver();

/* ******************************************************************************** */
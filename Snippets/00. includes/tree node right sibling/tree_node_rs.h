#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node_rs {
    char value;
    int idx;
    int parentIdx;
    int siblingIdx;
    int childIdx;
} tree_node_rs;

tree_node_rs* tree_node_rs_init_char(char);
tree_node_rs* tree_node_rs_init_all(int, int, int, int, char);
void tree_node_rs_deinit(tree_node_rs*);
void tree_node_rs_visit(tree_node_rs*);
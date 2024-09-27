#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node_rs {
    int idx;
    int parentIdx;
    char value;
} tree_node_rs;

tree_node_rs* tree_node_rs_init(int, int, char);
void tree_node_rs_deinit(tree_node_rs*);
void tree_node_rs_visit(tree_node_rs*);
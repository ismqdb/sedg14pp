#pragma once

#include <stdio.h>
#include <stdlib.h>

static const int blockSize = 25;

typedef struct tree_node_rs {
    int idx;
    int parentIdx;
} tree_node_rs;

tree_node_rs* tree_node_rs_init(int, int);
void tree_node_rs_deinit(tree_node_rs*);
void tree_node_rs_visit(tree_node_rs*);
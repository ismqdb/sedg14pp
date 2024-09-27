#pragma once

#include "../00. includes/tree node right sibling/tree_node_rs.h"

static const int blockSize = 25;

typedef struct {
    char *values;
    int currentSize;
    int allocatedSize;
} binary_tree_rs;

binary_tree_rs* binary_tree_rs_init(int);
int binary_tree_rs_add_node(binary_tree_rs*, tree_node_rs*, char);
void binary_tree_rs_deinit(binary_tree_rs*);
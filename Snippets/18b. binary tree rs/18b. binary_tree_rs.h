#pragma once

#include "../13. queue array/13. queue_a.h"

static const int block_size = 25;

typedef struct {
    int *parents;
    int *siblings;
    int *children;
    int current_size;
    int allocated_size;
} binary_tree_rs;

binary_tree_rs* binary_tree_rs_init(int);
void binary_tree_rs_deinit(binary_tree_rs*);

void binary_tree_rs_traverse(binary_tree_rs*);

int binary_tree_rs_driver();
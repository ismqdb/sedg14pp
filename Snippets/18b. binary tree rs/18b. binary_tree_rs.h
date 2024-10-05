#pragma once

#include "../00. includes/macros.h"
#include "../13. queue array/13. queue_a.h"

static const int block_size = 25;

typedef struct {
    char *key;

    char *next_parent;
    char *next_sibling;
    char *next_children;

    int current_parent;
    int current_sibling;
    int current_child;

    int head;
    int tail;

    int current_size;
    int allocated_size;
} binary_tree_rs;

binary_tree_rs* binary_tree_rs_init(int);
void binary_tree_rs_deinit(binary_tree_rs*);
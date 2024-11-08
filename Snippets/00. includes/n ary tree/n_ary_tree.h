#ifndef N_ARY_TREE_H
#define N_ARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

#include "../array/array.h"
#include "../tree_node_data_type.h"
#include "../alloc_macros.h"

#include "../../13. queue array/13. queue_a.h"

typedef struct {
    data_type type;

    union {
        char *chars;
    } keys;

    int *parent;
    int *child;
    int *sibling;

    int current_index;
    int current_size;
    int allocated_size;
    int block_size;
} n_ary_tree;

n_ary_tree n_ary_tree_create(data_type);
void n_ary_tree_destroy(n_ary_tree*);
int n_ary_tree_insert_char(n_ary_tree*, char);
int n_ary_tree_insert_child_char(n_ary_tree*, int, char);
int n_ary_tree_insert_sibling_char(n_ary_tree*, int, int, char);

int n_ary_tree_level_order(n_ary_tree*);
int n_ary_tree_level_order_driver();

#endif
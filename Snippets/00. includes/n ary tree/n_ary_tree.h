#ifndef N_ARY_TREE
#define N_ARY_TREE

#include <stdio.h>
#include <stdlib.h>

#include "../tree_node_data_type.h"
#include "../alloc_macros.h"

typedef struct {
    data_type type;

    union {
        int *ints;
    } keys;

    union {
        int *ints;
    } parent;

    union {
        int *ints;
    } child;

    int current_size;
    int allocated_size;
    int block_size;
} n_ary_tree;

#endif
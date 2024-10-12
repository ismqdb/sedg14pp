#ifndef N_ARY_NODE_H
#define N_ARY_NODE_H

typedef struct n_ary_node {
    int parent;
    struct n_ary_node **children;
} n_ary_node;

#endif
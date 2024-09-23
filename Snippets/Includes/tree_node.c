#pragma once

typedef enum {INT, TREE_NODE} data_type;

typedef struct tree_node {
    char info;
    struct tree_node* left;
    struct tree_node* right;
} tree_node;
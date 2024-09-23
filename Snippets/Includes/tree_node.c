#pragma once

typedef enum {INT, TREE_NODE} data_type;

typedef struct tree_node {
    char info;
    struct tree_node* left;
    struct tree_node* right;
} tree_node;

tree_node* n_init(char c){
    tree_node *n = (tree_node*)malloc(sizeof(tree_node));
    n->info = c;
    return n;
};

void n_deinit(tree_node *n){
    free(n);
}
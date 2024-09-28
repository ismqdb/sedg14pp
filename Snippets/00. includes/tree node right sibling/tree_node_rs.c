#include "./tree_node_rs.h"

tree_node_rs* tree_node_rs_init(char v){
    tree_node_rs *n = (tree_node_rs*)malloc(sizeof(tree_node_rs));
    n->value = v;

    return n;
};

void tree_node_rs_deinit(tree_node_rs *n){
    free(n);
}

void tree_node_rs_visit(tree_node_rs *t){
    
}
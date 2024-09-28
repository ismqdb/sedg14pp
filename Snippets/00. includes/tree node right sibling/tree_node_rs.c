#include "./tree_node_rs.h"

tree_node_rs* tree_node_rs_init(int idx, int parent, char v){
    tree_node_rs *n = (tree_node_rs*)malloc(sizeof(tree_node_rs));
    
    n->value = v;
    n->idx = idx;
    n->parentIdx = parent;

    return n;
};

void tree_node_rs_deinit(tree_node_rs *n){
    free(n);
}

void tree_node_rs_visit(tree_node_rs *t){
    
}
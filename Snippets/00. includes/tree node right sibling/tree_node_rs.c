#include "./tree_node_rs.h"

tree_node_rs* tree_node_rs_init(int idx, int p_idx){
    if(idx < 0 || p_idx < 0)
        return NULL;

    tree_node_rs *n = (tree_node_rs*)malloc(sizeof(tree_node_rs));
    n->idx = idx;
    n->parentIdx = p_idx;

    return n;
};

void tree_node_rs_deinit(tree_node_rs *n){
    free(n);
}

void tree_node_rs_visit(tree_node_rs *t){
    
}
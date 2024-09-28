#include "./tree_node_rs.h"

tree_node_rs* tree_node_rs_init_all(int idx, int parent, int sibling, int child, char v){
    tree_node_rs *n = (tree_node_rs*)malloc(sizeof(tree_node_rs));
    
    n->value = v;
    n->idx = idx;
    n->parentIdx = parent;

    n->siblingIdx = sibling < 0 ? -1 : sibling;
    n->childIdx = child < 0 ? -1 : child;

    return n;
};

tree_node_rs* tree_node_rs_init_char(char x){
    tree_node_rs *n = (tree_node_rs*)malloc(sizeof(tree_node_rs));

    n->value = x;
    n->idx = -1;
    n->parentIdx = -1;
    n->siblingIdx = -1;
    n->childIdx = -1;

    return n;
}

void tree_node_rs_deinit(tree_node_rs *n){
    free(n);
}

void tree_node_rs_visit(tree_node_rs *t){
    
}
#include "./18b. binary_tree_rs.h"

binary_tree_rs* binary_tree_rs_init(int size){
    if(size <= 0)
        return NULL;

    int alloc_size = (size/blockSize+1)*blockSize;

    binary_tree_rs *bt_rs = (binary_tree_rs*)malloc(sizeof(binary_tree_rs));
    bt_rs->currentSize = 0;
    bt_rs->allocatedSize = alloc_size;
    bt_rs->nodes = (tree_node_rs**)malloc(alloc_size* sizeof(tree_node_rs));

    return bt_rs;
}

void binary_tree_rs_deinit(binary_tree_rs *bt_rs){
    free(bt_rs->nodes);
    free(bt_rs);
}

int binary_tree_rs_add_node(binary_tree_rs *b_tree, tree_node_rs *t_node){

    if(b_tree->currentSize == (b_tree->allocatedSize)){
        b_tree->nodes = realloc(b_tree->nodes, b_tree->allocatedSize + blockSize);
        b_tree->allocatedSize += blockSize;
    }

    
    
    return 1;
}

tree_node_rs* tree_node_rs_get_parent(binary_tree_rs *b_tree, tree_node_rs *t_node){
    
}
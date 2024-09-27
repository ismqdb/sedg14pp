#include "./18b. binary_tree_rs.h"

binary_tree_rs* binary_tree_rs_init(int size){
    if(size <= 0)
        return NULL;

    int alloc_size = (size/blockSize+1)*blockSize;

    binary_tree_rs *bt_rs = (binary_tree_rs*)malloc(sizeof(binary_tree_rs));
    bt_rs->currentSize = 0;
    bt_rs->allocatedSize = alloc_size;
    bt_rs->values = (char*)malloc(alloc_size* sizeof(char));

    return bt_rs;
}

void binary_tree_rs_deinit(binary_tree_rs *bt_rs){
    free(bt_rs->values);
    free(bt_rs);
}

int binary_tree_rs_add_node(binary_tree_rs *b_tree, tree_node_rs *t_node, char value){
    if(t_node->idx <= 0 || b_tree == NULL)
        return 0;

    if(b_tree->currentSize == (b_tree->allocatedSize)){
        realloc(b_tree->values, b_tree->allocatedSize + blockSize);
        b_tree->allocatedSize += blockSize;
    }

    b_tree->values[t_node->idx] = t_node->value;
    return 1;
}
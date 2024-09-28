#include "./18b. binary_tree_rs.h"

binary_tree_rs* binary_tree_rs_init(int size){
    if(size <= 0)
        return NULL;

    int alloc_size = (size/block_size+1)*block_size;

    binary_tree_rs *bt_rs = (binary_tree_rs*)malloc(sizeof(binary_tree_rs));
    bt_rs->current_size = 0;
    bt_rs->allocated_size = alloc_size;
    //bt_rs->nodes = (tree_node_rs**)malloc(alloc_size* sizeof(tree_node_rs));
    bt_rs->parents = (int*)malloc(size*sizeof(int));
    bt_rs->siblings = (int*)malloc(size*sizeof(int));
    bt_rs->children = (int*)malloc(size*sizeof(int));

    return bt_rs;
}

void binary_tree_rs_deinit(binary_tree_rs *bt_rs){
   
    free(bt_rs);
}

void binary_tree_rs_traverse(binary_tree_rs *b_tree){
    
}

int binary_tree_rs_driver(){
    binary_tree_rs *b_tree = binary_tree_rs_init(50);

    

    binary_tree_rs_traverse(b_tree);
}
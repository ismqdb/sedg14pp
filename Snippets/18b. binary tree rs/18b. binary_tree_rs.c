#include "./18b. binary_tree_rs.h"

binary_tree_rs* binary_tree_rs_init(int size){
    if(size <= 0)
        return NULL;

    int alloc_size = (size/block_size+1)*block_size;

    binary_tree_rs *bt_rs = heap_alloc_sized(binary_tree_rs, 1);
    bt_rs->current_size = 0;
    bt_rs->allocated_size = alloc_size;
    
    bt_rs->key =            heap_alloc_sized(char, size);
    bt_rs->next_parent =    heap_alloc_sized(char, size);
    bt_rs->next_sibling =   heap_alloc_sized(char, size);
    bt_rs->next_children =  heap_alloc_sized(char, size);

    bt_rs->current_parent = 2;
    bt_rs->current_sibling = 2;
    bt_rs->current_child = 2;

    bt_rs->head = 0;
    bt_rs->tail = 1;

    return bt_rs;
}

void binary_tree_rs_deinit(binary_tree_rs *bt_rs){
    free(bt_rs);
}

void convert_to_bt_rs(binary_tree_rs *result, tree_node *t){
    if(t == NULL)
        return;

    while(t != NULL){
        convert_to_bt_rs(result, t->left);
        convert_to_bt_rs(result, t->right);

        // do stuff with t
    }
}
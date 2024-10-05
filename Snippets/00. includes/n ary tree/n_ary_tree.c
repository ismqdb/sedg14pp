#include "./n_ary_tree.h"

n_ary_tree n_ary_tree_create(data_type type){
    n_ary_tree tree;

    tree.type = type;

    tree.current_size = 0;
    tree.block_size = 50;
    tree.allocated_size = tree.block_size;

    switch(type){
        case N_ARY_NODE:
            tree.keys.ints = heap_alloc_sized(int, 50);
            tree.child.ints = heap_alloc_sized(int, 50);
            tree.parent.ints = heap_alloc_sized(int, 50);
        break;
    }

    return tree;
}

void n_ary_tree_destroy(n_ary_tree *tree){
    tree->current_size = 0;
    tree->block_size = 0;
    tree->allocated_size = 0;

    switch(tree->type){
        case N_ARY_NODE:
            free(tree->keys.ints);
            free(tree->child.ints);
            free(tree->parent.ints);
        break;
    }
}
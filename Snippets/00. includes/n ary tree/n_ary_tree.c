#include "./n_ary_tree.h"

n_ary_tree n_ary_tree_create(data_type type){
    n_ary_tree tree;

    tree.type = type;

    tree.current_size = 0;
    tree.current_index = 0;

    tree.block_size = 50;
    tree.allocated_size = tree.block_size;

    tree.parents = heap_alloc_sized(int, tree.block_size);

    switch(type){
        case N_ARY_TREE:
            tree.keys.chars =   heap_alloc_sized(char, tree.block_size);
        break;
    }

    return tree;
}

void n_ary_tree_destroy(n_ary_tree *tree){
    tree->current_size = 0;
    tree->block_size = 0;
    tree->allocated_size = 0;
    tree->current_index = 0;

    switch(tree->type){
        case N_ARY_TREE:
            free(tree->keys.chars);
        break;
    }
}

int n_ary_tree_insert_char(n_ary_tree *tree, char value, int parent_){
    tree->keys.chars[tree->current_index] = value;

    tree->parents[tree->current_index] = parent_;

    return tree->current_index++;
}
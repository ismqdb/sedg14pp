#include "./n_ary_tree.h"

n_ary_tree n_ary_tree_create(data_type type){
    n_ary_tree tree;

    tree.type = type;

    tree.current_size = 0;
    tree.current_index = 0;

    tree.block_size = 50;
    tree.allocated_size = tree.block_size;

    tree.parent     = heap_alloc_sized(int, tree.block_size);
    tree.child      = heap_alloc_sized(int, tree.block_size);
    tree.sibling    = heap_alloc_sized(int, tree.block_size);

    for(int i = 0; i < tree.block_size; i++)
        tree.parent[i] = tree.child[i] = tree.sibling[i] = -1;

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
            free(tree->parent);
            free(tree->child);
        break;
    }
}

int n_ary_tree_insert_char(n_ary_tree *tree, char value, int parent_){
    tree->keys.chars[tree->current_index] = value;

    tree->parent[tree->current_index] = parent_;

    if(parent_ > -1)
        tree->child[parent_] = tree->current_index;

    return tree->current_index++;
}

int n_ary_tree_insert_char_child(n_ary_tree* tree, int parent, char child){

}

int n_ary_tree_insert_char_sibling(n_ary_tree* tree, int parent, int existing_node, char sibling){

}

int n_ary_tree_level_order(n_ary_tree *tree){
    stack_a stack = stack_a_init(INT, 50);

    stack_a_deinit(&stack);
}
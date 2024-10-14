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

int n_ary_tree_insert_char(n_ary_tree *tree, char value){
    tree->keys.chars[tree->current_index] = value;

    return tree->current_index++;
}

int n_ary_tree_insert_child_char(n_ary_tree* tree, int parent, char child){
    tree->keys.chars[tree->current_index] = child;

    tree->parent[tree->current_index] = parent;
    tree->child[parent] = tree->current_index;

    return tree->current_index++;
}

int n_ary_tree_insert_sibling_char(
        n_ary_tree* tree, 
        int parent, 
        int existing_node, 
        char sibling
    ){
    tree->keys.chars[tree->current_index] = sibling;

    tree->parent[existing_node] = -1;
    tree->parent[tree->current_index] = parent;

    tree->sibling[existing_node] = tree->current_index;

    return tree->current_index++;
}

int n_ary_tree_level_order(n_ary_tree *tree){
    queue_a queue = queue_a_init(INT, 50);

    int current_node = 0;
    int current_sibling;

    while(!(
        tree->sibling[current_node] == -1 && 
        tree->child[current_node] == -1 && 
        queue_a_is_empty(&queue))){
        for(
            current_sibling = tree->sibling[current_node];
            current_sibling != -1;
            current_sibling = tree->sibling[current_sibling]
        )
            queue_a_put_int(&queue, current_sibling);

        if(tree->child[current_node] != -1)
            queue_a_put_int(&queue, tree->child[current_node]);

        printf("%c ", tree->keys.chars[current_node]);

        current_node = queue_a_get_int(&queue);
    }

    putchar(10);

    queue_a_deinit(&queue);
}
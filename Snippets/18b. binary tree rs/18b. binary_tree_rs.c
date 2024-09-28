#include "./18b. binary_tree_rs.h"

binary_tree_rs* binary_tree_rs_init(int size){
    if(size <= 0)
        return NULL;

    int alloc_size = (size/block_size+1)*block_size;

    binary_tree_rs *bt_rs = (binary_tree_rs*)malloc(sizeof(binary_tree_rs));
    bt_rs->current_size = 0;
    bt_rs->allocated_size = alloc_size;
    bt_rs->nodes = (tree_node_rs**)malloc(alloc_size* sizeof(tree_node_rs));
    bt_rs->parents = (int*)malloc(size*sizeof(int));
    bt_rs->siblings = (int*)malloc(size*sizeof(int));
    bt_rs->children = (int*)malloc(size*sizeof(int));

    return bt_rs;
}

void binary_tree_rs_deinit(binary_tree_rs *bt_rs){
    free(bt_rs->nodes);
    free(bt_rs);
}

int binary_tree_rs_add_node(binary_tree_rs *b_tree, tree_node_rs *t_node){

    if(b_tree->current_size == (b_tree->allocated_size)){
        int alloc_size = b_tree->allocated_size + block_size;

        b_tree->nodes = realloc(b_tree->nodes, alloc_size);
        b_tree->parents = realloc(b_tree->parents, alloc_size);
        b_tree->siblings = realloc(b_tree->siblings, alloc_size);
        b_tree->children = realloc(b_tree->children, alloc_size);

        b_tree->allocated_size += block_size;
    }

    b_tree->nodes[t_node->idx] = t_node;
    b_tree->parents[t_node->idx] = t_node->parentIdx;
    b_tree->siblings[t_node->idx] = t_node->siblingIdx;
    b_tree->children[t_node->idx] = t_node->childIdx;
   
    return 1;
}

int binary_tree_rs_driver(){
    binary_tree_rs *b_tree = binary_tree_rs_init(50);

    tree_node_rs *mul1  =   tree_node_rs_init(0, 0, -1, 1, '*');
    tree_node_rs *a     =   tree_node_rs_init(1, 0, 2, -1, 'A');
    tree_node_rs *add1  =   tree_node_rs_init(2, -1, -1, 3, '+');
    tree_node_rs *mul2  =   tree_node_rs_init(3, 2, 4, 5, '*');
    tree_node_rs *f     =   tree_node_rs_init(4, -1, -1, -1, 'F');
    tree_node_rs *add2  =   tree_node_rs_init(5, 3, 6, 7, '*');
    tree_node_rs *mul3  =   tree_node_rs_init(6, -1, -1, 9, '*');
    tree_node_rs *b     =   tree_node_rs_init(7, 5, 8, -1, 'B');
    tree_node_rs *c     =   tree_node_rs_init(8, -1, -1, -1, 'C');
    tree_node_rs *d     =   tree_node_rs_init(9, 6, 10, -1, 'D');
    tree_node_rs *e     =   tree_node_rs_init(10, -1, -1, -1, 'E');
    
    binary_tree_rs_add_node(b_tree, mul1);
    binary_tree_rs_add_node(b_tree, a);
    binary_tree_rs_add_node(b_tree, add1);
    binary_tree_rs_add_node(b_tree, mul2);
    binary_tree_rs_add_node(b_tree, f);
    binary_tree_rs_add_node(b_tree, add2);
    binary_tree_rs_add_node(b_tree, mul3);
    binary_tree_rs_add_node(b_tree, b);
    binary_tree_rs_add_node(b_tree, c);
    binary_tree_rs_add_node(b_tree, d);
    binary_tree_rs_add_node(b_tree, e);
}
#include "./18b. binary_tree_rs.h"

binary_tree_rs* binary_tree_rs_init(int size){
    if(size <= 0)
        return NULL;

    int alloc_size = (size/block_size+1)*block_size;

    binary_tree_rs *bt_rs = (binary_tree_rs*)malloc(sizeof(binary_tree_rs));
    bt_rs->currentSize = 0;
    bt_rs->allocatedSize = alloc_size;
    bt_rs->nodes = (tree_node_rs**)malloc(alloc_size* sizeof(tree_node_rs));
    bt_rs->parents = (int*)malloc(size*sizeof(int));

    return bt_rs;
}

void binary_tree_rs_deinit(binary_tree_rs *bt_rs){
    free(bt_rs->nodes);
    free(bt_rs);
}

int binary_tree_rs_add_node(binary_tree_rs *b_tree, tree_node_rs *t_node){

    if(b_tree->currentSize == (b_tree->allocatedSize)){
        int alloc_size = b_tree->allocatedSize + block_size;

        b_tree->nodes = realloc(b_tree->nodes, alloc_size);
        b_tree->parents = realloc(b_tree->parents, alloc_size);

        b_tree->allocatedSize += block_size;
    }

    b_tree->nodes[t_node->idx] = t_node;
    b_tree->parents[t_node->idx] = t_node->parentIdx;
   
    return 1;
}

int binary_tree_rs_driver(){
    binary_tree_rs *b_tree = binary_tree_rs_init(50);

    tree_node_rs *a =   tree_node_rs_init(1, 3, 'A');

    tree_node_rs *s =   tree_node_rs_init(2, 3, 'S');
    tree_node_rs *a2 =  tree_node_rs_init(3, 10, 'A');
    tree_node_rs *m =   tree_node_rs_init(4, 8, 'M');
    tree_node_rs *p =   tree_node_rs_init(5, 8, 'P');
    tree_node_rs *l =   tree_node_rs_init(6, 8, 'L');
    tree_node_rs *e =   tree_node_rs_init(7, 8, 'E'); 

    tree_node_rs *t =   tree_node_rs_init(8, 9, 'T');
    tree_node_rs *r =   tree_node_rs_init(9, 10, 'R');
    tree_node_rs *e2 =  tree_node_rs_init(10, 10, 'E');
    tree_node_rs *e3 =  tree_node_rs_init(11, 10, 'E');

    binary_tree_rs_add_node(b_tree, a);
    binary_tree_rs_add_node(b_tree, s);
    binary_tree_rs_add_node(b_tree, a2);
    binary_tree_rs_add_node(b_tree, m);
    binary_tree_rs_add_node(b_tree, p);
    binary_tree_rs_add_node(b_tree, l);
    binary_tree_rs_add_node(b_tree, e);
    binary_tree_rs_add_node(b_tree, t);
    binary_tree_rs_add_node(b_tree, r);
    binary_tree_rs_add_node(b_tree, e2);
    binary_tree_rs_add_node(b_tree, e3);
}
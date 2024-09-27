#include <stdio.h>
#include <stdlib.h>

#include "./Snippets/18b. binary tree rs/18b. binary_tree_rs.h"

int main(){
    binary_tree_rs *b_tree = binary_tree_rs_init(50);
    tree_node_rs *t1 = tree_node_rs_init(1, 3, 'a');

    binary_tree_rs_add_node(b_tree, t1);
}
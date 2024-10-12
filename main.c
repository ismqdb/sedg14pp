#include <stdio.h>
#include <stdlib.h>

#include "./Snippets/00. includes/n ary tree/n_ary_tree.h"

int main(){
    n_ary_tree tree = n_ary_tree_create(N_ARY_TREE);

    int root = n_ary_tree_insert_char(&tree, 'E', -1);

    int a1 = n_ary_tree_insert_char(&tree, 'A', root);
    int r1 = n_ary_tree_insert_char(&tree, 'R', root);
    int e1 = n_ary_tree_insert_char(&tree, 'E', root);

    int a2 = n_ary_tree_insert_char(&tree, 'A', a1);
    int s1 = n_ary_tree_insert_char(&tree, 'S', a1);

    int t1 = n_ary_tree_insert_char(&tree, 'T', r1);

    int m1 = n_ary_tree_insert_char(&tree, 'M', t1);
    int p1 = n_ary_tree_insert_char(&tree, 'P', t1);
    int l1 = n_ary_tree_insert_char(&tree, 'L', t1);
    int e2 = n_ary_tree_insert_char(&tree, 'E', t1);
}
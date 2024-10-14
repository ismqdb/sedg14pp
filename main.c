#include <stdio.h>
#include <stdlib.h>

#include "./Snippets/00. includes/n ary tree/n_ary_tree.h"

int main(){
    n_ary_tree tree = n_ary_tree_create(N_ARY_TREE);

    int root = n_ary_tree_insert_char(&tree, 'E');

    int a1 = n_ary_tree_insert_child_char(&tree, root, 'A');
    int r1 = n_ary_tree_insert_sibling_char(&tree, root, a1, 'R');
    int e1 = n_ary_tree_insert_sibling_char(&tree, root, r1, 'E');

    int a2 = n_ary_tree_insert_child_char(&tree, a1, 'A');
    int s1 = n_ary_tree_insert_sibling_char(&tree, a1, a2, 'S');

    int t1 = n_ary_tree_insert_child_char(&tree, r1, 'T');

    int m1 = n_ary_tree_insert_child_char(&tree, t1, 'M');
    int p1 = n_ary_tree_insert_sibling_char(&tree, t1, m1, 'P');
    int l1 = n_ary_tree_insert_sibling_char(&tree, t1, p1, 'L');
    int e2 = n_ary_tree_insert_sibling_char(&tree, t1, l1, 'E');

    n_ary_tree_level_order(&tree);
}
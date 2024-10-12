#include <stdio.h>
#include <stdlib.h>

#include "./Snippets/00. includes/n ary tree/n_ary_tree.h"

int main(){
    n_ary_tree tree = n_ary_tree_create(N_ARY_TREE);

    n_ary_tree_insert_char(&tree, 'E', -1, -1);
    n_ary_tree_insert_char(&tree, 'A', 0, -1);
}
#include <stdio.h>
#include <stdlib.h>

#include "Snippets/09. linked list/09. linked_list.h"
#include "Snippets/18. tree traversals/18. tree_traversals.h"

int main(){
    tree_node *t = build_parse_tree();
    tree_node *f = convert_to_forest_binary_tree(t);
}
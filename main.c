#include <stdio.h>
#include <stdlib.h>

#include "Snippets/00. includes/parse tree/parse_tree.h"
#include "Snippets/18. tree traversals/18. tree_traversals.h"
#include "Snippets/22. recursion removal/22. recursion_removal.h"

int main(){
    tree_node *t = build_parse_tree();

    pre_order(t);
    putchar(10);
    remove_recursion_2(t);
    putchar(10);
    remove_recursion_3(t);
    putchar(10);
    remove_recursion_4(t);
    putchar(10);
}

// A B C + D E * * F + *
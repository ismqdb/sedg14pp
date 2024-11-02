#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Snippets/00. includes/parse tree/parse_tree.h"

int main(){
    tree_node *t = build_parse_tree();
    draw_binary_tree(t);
}

// A B C + D E * * F + *
#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node_rs {
    char value;
} tree_node_rs;

tree_node_rs* tree_node_rs_init(char);
void tree_node_rs_deinit(tree_node_rs*);
void tree_node_rs_visit(tree_node_rs*);
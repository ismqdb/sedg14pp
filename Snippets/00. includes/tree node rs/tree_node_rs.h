/* ******************************************************************************** */

#pragma once

#include <stdio.h>
#include "../../13. queue array/13. queue_a.h"

#include "../parse tree/parse_tree.h"

/* ******************************************************************************** */

struct tree_node_rs {
    union {
        int integer;
    } value;

    struct tree_node_rs *child;
    struct tree_node_rs *sibling;
    struct tree_node_rs *parent;
};

/* ******************************************************************************** */


struct tree_node_rs* create_node(int);
struct tree_node_rs* insert_child(struct tree_node_rs*, int);
struct tree_node_rs* insert_sibling(struct tree_node_rs*, struct tree_node_rs*, int);

void level_order_traversal(struct tree_node_rs*);
void external_path_length_rs(struct tree_node_rs*, int, int*);

/* ******************************************************************************** */

void visit_tree_node_rs(struct tree_node_rs*);

/* ******************************************************************************** */
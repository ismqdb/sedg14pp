/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>

/* ******************************************************************************** */

#include "../00. includes/tree node/tree_node.h"
#include "../00. includes/parse tree/parse_tree.h"

/* ******************************************************************************** */

#include "../12. stack array/12. stack_a.h"
#include "../13. queue array/13. queue_a.h"

/* ******************************************************************************** */

void level_order(tree_node*);
void pre_order(tree_node*);
void in_order(tree_node*);
void post_order(tree_node*);
void pre_order_iterative(tree_node*);
void pre_order_recursive(tree_node*);
void in_order_recursive(tree_node*);

/* ******************************************************************************** */
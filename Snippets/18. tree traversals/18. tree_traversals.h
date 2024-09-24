#pragma once

#include <stdio.h>

#include "../00. includes/tree node/tree_node.h"

#include "../18a. parse tree/18a. parse_tree.h"
#include "../12. stack array/12. stack_a.h"
#include "../13. queue array/13. queue_a.h"

tree_node* convert_to_forest_binary_tree(tree_node*);

void level_order(tree_node*);
void pre_order(tree_node*);
void in_order(tree_node*);
void post_order(tree_node*);
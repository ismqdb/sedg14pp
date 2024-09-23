#pragma once

#include <stdio.h>

#include "../00. Includes/tree node/tree_node.h"
#include "../18a. parse tree/18a. parse_tree.h"
#include "../12. stack array/12. stack_a.h"
#include "../13. queue array/13. queue_a.h"

void pre_order(tree_node*);
void pre_order_iter(tree_node*);
void pre_order_recursive(tree_node*);
void in_order_recursive(tree_node*);
void remove_recursion_1(tree_node*);
void remove_recursion_2(tree_node*);
void remove_recursion_3(tree_node*);
int remove_recursion_main();
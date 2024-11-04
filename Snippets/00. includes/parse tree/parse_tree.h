#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../../12. stack array/12. stack_a.h"
#include "../../13. queue array/13. queue_a.h"

tree_node* build_parse_tree();
int is_new_level(int*, int);
void draw_binary_tree_iterative(tree_node*);
void draw_binary_tree_recursive(tree_node*);
/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>
#include <stack>
#include <queue>

#include "../tree node/treeNode.hpp"

/* ******************************************************************************** */

treeNode* buildParseTree();
int is_new_level(int*, int);
void draw_binary_tree_iterative(treeNode*);
void draw_binary_tree_recursive(treeNode*);

/* ******************************************************************************** */
/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>

/* ******************************************************************************** */

#include "../00. includes/tree node/treeNode.h"
#include "../00. includes/parse tree/parseTree.h"

/* ******************************************************************************** */

#include "../12. stack array/12. stackArray.h"
#include "../13. queue array/13. queue_a.h"

/* ******************************************************************************** */

void level_order(treeNode*);
void pre_order(treeNode*);
void in_order(treeNode*);
void post_order(treeNode*);
void pre_order_iterative(treeNode*);
void pre_order_recursive(treeNode*);
void in_order_recursive(treeNode*);

/* ******************************************************************************** */
/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>

/* ******************************************************************************** */

#include "../00. includes/tree node/treeNode.h"
#include "../00. includes/parse tree/parseTree.h"

/* ******************************************************************************** */

#include "../12. stack/12. stackArray.h"
#include "../13. queue/13. queueArray.h"

/* ******************************************************************************** */

void levelOrder(treeNode*);
void preOrder(treeNode*);
void inOrder(treeNode*);
void postOrder(treeNode*);
void preOrderIterative(treeNode*);
void preOrderRecursive(treeNode*);
void inOrderRecursive(treeNode*);

/* ******************************************************************************** */
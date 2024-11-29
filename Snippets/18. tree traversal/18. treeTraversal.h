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

void levelOrder(struct treeNode*);
void preOrder(struct treeNode*);
void inOrder(struct treeNode*);
void postOrder(struct treeNode*);
void preOrderIterative(struct treeNode*);
void preOrderRecursive(struct treeNode*);
void inOrderRecursive(struct treeNode*);

/* ******************************************************************************** */
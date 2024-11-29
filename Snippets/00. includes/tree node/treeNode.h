/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/* ******************************************************************************** */

#include "../parse tree/parseTree.h"

/* ******************************************************************************** */

typedef struct treeNode {
    char info;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

/* ******************************************************************************** */

struct tnodePair {
    struct treeNode *node;
    int index;
};

/* ******************************************************************************** */

treeNode* treeNodeInit();
treeNode* treeNodeInitChar(char);

/* ******************************************************************************** */

void treeNodeDeinit(treeNode*);

/* ******************************************************************************** */

int binaryTreeDrawRecursive(treeNode*, struct tnodePair**, int, int);
void externalPathLenTreeNode(treeNode*, int, int*);
int binaryTreeDrawRecursiveDriver();
void visitTreeNode(treeNode*);

/* ******************************************************************************** */
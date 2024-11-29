/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/* ******************************************************************************** */

#include "../parse tree/parseTree.h"

/* ******************************************************************************** */

struct treeNode {
    char info;
    struct treeNode* left;
    struct treeNode* right;
};

/* ******************************************************************************** */

struct tnodePair {
    struct treeNode *node;
    int index;
};

/* ******************************************************************************** */

struct treeNode* treeNodeInit();
struct treeNode* treeNodeInitChar(char);

/* ******************************************************************************** */

void treeNodeDeinit(struct treeNode*);

/* ******************************************************************************** */

int binaryTreeDrawRecursive(struct treeNode*, struct tnodePair**, int, int);
void externalPathLenTreeNode(struct treeNode*, int, int*);
int binaryTreeDrawRecursiveDriver();
void visitTreeNode(struct treeNode*);
int tnodeCompare(const void*, const void*);

/* ******************************************************************************** */
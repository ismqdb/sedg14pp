/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdlib.h>

/* ******************************************************************************** */

#include "../00. includes/treeNodeDataType.h"
#include "../00. includes/tree node/tree_node.h"

/* ******************************************************************************** */

typedef struct stackArray {
    treeNodeDataType type;
    union {
        int* integer;
        struct treeNode** treeNode;
    } data;
    int p;
    int currentSize;
    int chunkSize;
} stackArray;

/* ******************************************************************************** */

void stackArrayPushInt(stackArray*, int);
void stackArrayPushTreeNode(stackArray*, struct treeNode*);

/* ******************************************************************************** */

int stackArrayPopInt(stackArray*);
struct treeNode* stackArrayPopTreeNode(stackArray*);

/* ******************************************************************************** */

stackArray stackArrayInit(treeNodeDataType, int);
void stackArrayDeinit(stackArray*);

/* ******************************************************************************** */

int stackArrayIsEmpty(stackArray*);
int stackArraySize(stackArray*);

/* ******************************************************************************** */
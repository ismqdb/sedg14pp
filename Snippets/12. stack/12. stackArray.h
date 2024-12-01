/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdlib.h>

/* ******************************************************************************** */

#include "../00. includes/treeNodeDataType.h"
#include "../00. includes/tree node/treeNode.h"

/* ******************************************************************************** */

struct stackArray {
    treeNodeDataType type;
    union {
        int* integer;
        struct treeNode** treeNode;
    } data;
    int p;
    int currentSize;
    int chunkSize;
};

/* ******************************************************************************** */

void stackArrayPushInt(struct stackArray*, int);
void stackArrayPushTreeNode(struct stackArray*, struct treeNode*);

/* ******************************************************************************** */

int stackArrayPopInt(struct stackArray*);
struct treeNode* stackArrayPopTreeNode(struct stackArray*);

/* ******************************************************************************** */

struct stackArray stackArrayInit(treeNodeDataType, int);
void stackArrayDeinit(struct stackArray*);

/* ******************************************************************************** */

int stackArrayIsEmpty(struct stackArray*);
int stackArraySize(struct stackArray*);

/* ******************************************************************************** */
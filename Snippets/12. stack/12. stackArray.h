/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdlib.h>
#include <pthread.h>

/* ******************************************************************************** */

#include "../00. includes/treeNodeDataType.h"
#include "../00. includes/tree node/treeNode.h"

#include "../00. includes/allocMacros.h"
#include "../00. includes/errorMacros.h"

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

    pthread_mutex_t mutex;
    pthread_cond_t hasDataCondVar;
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
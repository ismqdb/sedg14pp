/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdlib.h>

/* ******************************************************************************** */

#include "../00. includes/treeNodeDataType.h"
#include "../00. includes/tree node/treeNode.h"
#include "../00. includes/tree node RS/treeNodeRS.h"

/* ******************************************************************************** */

typedef struct queueArray {
    treeNodeDataType type;
    union {
        int* integer;
        struct treeNode **treeNode;
        struct treeNodeRS **tree_node_rs;
    } data;
    int head;
    int tail;
    int chunk_size;
    int current_size;
} queueArray;

/* ******************************************************************************** */

void queueArrayPutInt(queueArray*, int);
void queueArrayPutTreeNode(queueArray*, struct treeNode*);
void queueArrayPutTreeNodeRS(queueArray*, struct treeNodeRS*);

/* ******************************************************************************** */

int queueArrayGetInt(queueArray*);
struct treeNode* queueArrayGetTreeNode(queueArray*);
struct treeNodeRS* queueArrayGetTreeNodeRS(queueArray*);

/* ******************************************************************************** */

queueArray queueArrayInit(treeNodeDataType, int);
void queueArrayDeinit(queueArray*);

/* ******************************************************************************** */

int queueArrayIsEmpty(queueArray*);

/* ******************************************************************************** */
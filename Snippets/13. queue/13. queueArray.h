/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdlib.h>

/* ******************************************************************************** */

#include "../00. includes/treeNodeDataType.h"
#include "../00. includes/tree node/treeNode.h"
#include "../00. includes/tree node RS/treeNodeRS.h"

/* ******************************************************************************** */

struct queueArray {
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
};

/* ******************************************************************************** */

void queueArrayPutInt(struct queueArray*, int);
void queueArrayPutTreeNode(struct queueArray*, struct treeNode*);
void queueArrayPutTreeNodeRS(struct queueArray*, struct treeNodeRS*);

/* ******************************************************************************** */

int queueArrayGetInt(struct queueArray*);
struct treeNode* queueArrayGetTreeNode(struct queueArray*);
struct treeNodeRS* queueArrayGetTreeNodeRS(struct queueArray*);

/* ******************************************************************************** */

struct queueArray queueArrayInit(treeNodeDataType, int);
void queueArrayDeinit(struct queueArray*);

/* ******************************************************************************** */

int queueArrayIsEmpty(struct queueArray*);

/* ******************************************************************************** */
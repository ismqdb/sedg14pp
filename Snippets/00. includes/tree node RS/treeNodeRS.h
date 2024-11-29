/* ******************************************************************************** */

#pragma once

#include <stdio.h>
#include "../../13. queue/13. queueArray.h"

#include "../parse tree/parseTree.h"

/* ******************************************************************************** */

struct treeNodeRS {
    union {
        int integer;
    } value;

    struct treeNodeRS *child;
    struct treeNodeRS *sibling;
    struct treeNodeRS *parent;
};

/* ******************************************************************************** */

struct treeNodeRS* createNode(int);
struct treeNodeRS* insertChild(struct treeNodeRS*, int);
struct treeNodeRS* insertSibling(struct treeNodeRS*, struct treeNodeRS*, int);

/* ******************************************************************************** */

void treeNodeRSLevelOrderTraversal(struct treeNodeRS*);
void treeNodeRSExternalPathLen(struct treeNodeRS*, int, int*);

/* ******************************************************************************** */

void treeNodeRSVisit(struct treeNodeRS*);

/* ******************************************************************************** */
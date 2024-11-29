/* ******************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/* ******************************************************************************** */

#include "../treeNodeDataType.h"
#include "../allocMacros.h"

/* ******************************************************************************** */

struct array {
    treeNodeDataType type;

    union {
        int *ints;
    } data;

    int currentSize;
    int allocatedSize;
    int blockSize;
};

/* ******************************************************************************** */

struct array createArray(treeNodeDataType);
void destroyArray(struct array*);
int insertInt(struct array*, int);

/* ******************************************************************************** */

#endif

/* ******************************************************************************** */
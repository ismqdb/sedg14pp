/* ******************************************************************************** */

#include "./array.h"

/* ******************************************************************************** */

struct array createArray(treeNodeDataType type){
    struct array a;

    a.currentSize = 0;
    a.blockSize = 25;
    a.allocatedSize = a.blockSize;
    
    switch(type){
        case INT:
            a.data.ints = heapAllocSized(int, a.currentSize);
        break;
    }

    return a;
}

/* ******************************************************************************** */

void destroyArray(struct array *a){
    a->currentSize = 0;

    switch(a->type){
        case INT:
            free(a->data.ints);
        break;
    }
}

/* ******************************************************************************** */

int insertInt(struct array *a, int value){
    if(a->currentSize == a->allocatedSize){
        a->allocatedSize += 25;
        a->data.ints = heapRealloc(int, a->data.ints, a->allocatedSize);
    }
    a->data.ints[a->currentSize] = value;
    a->currentSize++;
}

/* ******************************************************************************** */
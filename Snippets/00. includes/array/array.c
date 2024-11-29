/* ******************************************************************************** */

#include "./array.h"

/* ******************************************************************************** */

array createArray(treeNodeDataType type){
    array a;

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

void destroyArray(array *a){
    a->currentSize = 0;

    switch(a->type){
        case INT:
            free(a->data.ints);
        break;
    }
}

/* ******************************************************************************** */

int insertInt(array *a, int value){
    if(a->currentSize == a->allocatedSize){
        a->allocatedSize += 25;
        a->data.ints = heapRealloc(int, a->data.ints, a->allocatedSize);
    }
    a->data.ints[a->currentSize] = value;
    a->currentSize++;
}

/* ******************************************************************************** */
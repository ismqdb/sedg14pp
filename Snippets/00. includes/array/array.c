/* ******************************************************************************** */

#include "./array.h"

/* ******************************************************************************** */

array create_array(treeNodeDataType type){
    array a;

    a.current_size = 0;
    a.block_size = 25;
    a.allocated_size = a.block_size;
    
    switch(type){
        case integer:
            a.data.ints = heapAllocSized(int, a.current_size);
        break;
    }

    return a;
}

/* ******************************************************************************** */

void destroy_array(array *a){
    a->current_size = 0;

    switch(a->type){
        case integer:
            free(a->data.ints);
        break;
    }
}

/* ******************************************************************************** */

int insert_int(array *a, int value){
    if(a->current_size == a->allocated_size){
        a->allocated_size += 25;
        a->data.ints = heapRealloc(int, a->data.ints, a->allocated_size);
    }
    a->data.ints[a->current_size] = value;
    a->current_size++;
}

/* ******************************************************************************** */
#include "./array.h"

array create_array(data_type type){
    array a;

    a.current_size = 0;
    a.block_size = 25;
    a.allocated_size = a.block_size;
    
    switch(type){
        case INT:
            a.data.ints = heap_alloc_sized(int, 50);
        break;
    }

    return a;
}

void destroy_array(array *a){
    a->current_size = 0;

    switch(a->type){
        case INT:
            free(a->data.ints);
        break;
    }
}

int insert_int(array *a, int value){
    if(a->current_size == a->allocated_size){
        a->allocated_size += 25;
        a->data.ints = heap_realloc(int, a->data.ints, a->allocated_size);
    }
    a->data.ints[a->current_size] = value;
    a->current_size++;
}
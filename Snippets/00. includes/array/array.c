#include "./array.h"

array create_array(data_type type){
    array a;

    a.current_size = 0;
    a.max_size = 25;
    
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
    if(a->current_size == a->max_size){
        a->max_size += 25;
        a->data.ints = (int*)realloc(a->data.ints, a->max_size*sizeof(int));
    }
    a->data.ints[a->current_size] = value;
    a->current_size++;
}

void populate(array *a, char *values){
    for(int i = 0; values[i] != '\0'; i++)
        insert_int(a, values[i]);
}
#include "./alloc_macros.h"

#define define_array(type) \
    typedef struct { \
        type *data; \
        int current_size; \
        int allocated_size; \
        int block_size; \
    } array_##type

#define create_array(type) array_##type create_array_##type(int b_size){ \
        array_##type a; \
        a.current_size = 0; \
        a.block_size = b_size; \
        a.allocated_size = a.block_size;  \
        a.data = heap_alloc_sized(type, a.current_size); \
        return a; \
    }
    
#define destroy_array(type) void destroy_array_##type(array_##type *a){ \
        a->current_size = 0; \
        free(a->data); \
    }
    
#define insert_array(type) int insert_array_##type(array_##type *a, type value){ \
        if(a->current_size == a->allocated_size){ \
            a->allocated_size += a->block_size; \
            heap_realloc(type, a->data, a->allocated_size); \
        }\
        a->data[a->current_size] = value; \
        a->current_size++; \
    }
    
#define populate_array(type) void populate_array_##type(array_##type *a, type *values) { \
        for(int i = 0; values[i] != '\0'; i++) \
            insert_array_##type(a, values[i]); \
    }
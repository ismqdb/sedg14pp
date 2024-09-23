#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct parallel_array {
    char *key;
    char *next;
    char current, head, z; 
} parallel_array;

parallel_array init_parallel_array(int);
void deinit_parallel_array(parallel_array);
void parallel_array_delete_next(parallel_array, char);
char parallel_array_insert_after(parallel_array, char, char);
void parallel_array_print_all(parallel_array);
int parallel_array_main();
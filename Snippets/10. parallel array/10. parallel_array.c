#include "./10. parallel_array.h"

parallel_array init_parallel_array(int size){
    parallel_array array;

    array.key = (char*)malloc(size*sizeof(char));
    array.next = (char*)malloc(size*sizeof(char));

    array.head = 0;
    array.z = 1;
    array.current = 2;

    array.next[array.head] = array.z;
    array.next[array.z] = array.z;

    return array;
}

void deinit_parallel_array(parallel_array *array){
    free(array->key);
    free(array->next);
}

void parallel_array_delete_next(parallel_array *array, char t){
    array->next[t] = array->next[array->next[t]];
}

char parallel_array_insert_after(parallel_array *array, char newValue, char existing){
    array->key[array->current] = newValue;

    array->next[array->current] = array->next[existing];
    array->next[existing] = array->current;

    return array->current++;
}

void parallel_array_print_all(parallel_array *array){
    char x = array->next[array->head];

    while(x != array->next[x]){
        printf("%c ", array->key[x]);
        x = array->next[x];
    }

    putchar(10);
}

int parallel_array_main(){
    parallel_array array = init_parallel_array(10);

    int s = parallel_array_insert_after(&array, 'S', 0);
    int l = parallel_array_insert_after(&array, 'L', 0);
    int a = parallel_array_insert_after(&array, 'A', 0);

    int i = parallel_array_insert_after(&array, 'I', l);
    int t = parallel_array_insert_after(&array, 'T', s);

    int n = parallel_array_insert_after(&array, 'N', a);
    int e = parallel_array_insert_after(&array, 'E', n);
    int w = parallel_array_insert_after(&array, 'W', e);

    int b1 = parallel_array_insert_after(&array, ' ', a);
    int b2 = parallel_array_insert_after(&array, ' ', w);

    parallel_array_print_all(&array);
}
/* ******************************************************************************** */

#include "./10. parray.h"

/* ******************************************************************************** */

struct parray parrayInit(int size){
    struct parray array;

    array.key = (char*)malloc(size*sizeof(char));
    array.next = (char*)malloc(size*sizeof(char));

    array.head = 0;
    array.tail = 1;
    array.current = 2;

    array.next[array.head] = array.tail;
    array.next[array.tail] = array.tail;

    return array;
}

/* ******************************************************************************** */

void parrayDeinit(struct parray *array){
    free(array->key);
    free(array->next);
}

/* ******************************************************************************** */

void parrayDeleteNext(struct parray *array, char t){
    array->next[t] = array->next[array->next[t]];
}

/* ******************************************************************************** */

char parrayInsertAfter(struct parray *array, char newValue, char existing){
    array->key[array->current] = newValue;

    array->next[array->current] = array->next[existing];
    array->next[existing] = array->current;

    return array->current++;
}

/* ******************************************************************************** */

void parrayPrintAll(struct parray *array){
    char x = array->next[array->head];

    while(x != array->next[x]){
        printf("%c ", array->key[x]);
        x = array->next[x];
    }

    putchar(10);
}

/* ******************************************************************************** */
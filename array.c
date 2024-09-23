#include <stdio.h>
#include <stdlib.h>

static struct array {
    char *start;
    int currentSize;
    int maxSize;
};

struct array createArray(){
    struct array a;
    a.currentSize = 0;
    a.maxSize = 25;
    a.start = (char*)malloc(25*sizeof(char));
    return a;
}

void destroyArray(struct array *a){
    a->currentSize = 0;
    free(a->start);
}

int insert(struct array *a, int value){
    if(a->currentSize == a->maxSize){
        a->maxSize += 25;
        a->start = (char*)realloc(a->start, a->maxSize*sizeof(char));
    }
    a->start[a->currentSize] = value;
    a->currentSize++;
}

void populate(struct array *a, char *values){
    for(int i = 0; values[i] != '\0'; i++)
        insert(a, values[i]);
}
#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct array {
    char *start;
    int currentSize;
    int maxSize;
} array;

array createArray();
void destroyArray(array*);
int insert(array*, int);
void populate(array*, char*);
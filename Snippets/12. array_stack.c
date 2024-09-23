#include <stdlib.h>

static int *stack;
static int p;
static int currentSize = 0;
static int chuckSize = 25;

void push(int v){
    if(p == currentSize){
        currentSize += chuckSize;
        stack = (int*)realloc(stack, currentSize*sizeof(int));
    }
    stack[p++] = v;
}

int pop(){
    return stack[--p];
}

void stack_init(int size){
    if(size <= 0)
        return;
    stack = (int*)malloc(size*sizeof(int));
    p = 0;
    currentSize += size;
}

void stack_deinit(){
    p = 0;
    free(stack);
}

int is_empty(){
    return !p;
}
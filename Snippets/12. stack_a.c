#include <stdlib.h>

typedef struct stack_a {
    int *stack;
    int p;
    int current_size;
    int chunk_size;
} stack_a;

void push(stack_a stack,int v){
    if(stack.p == stack.current_size){
        stack.current_size += stack.chunk_size;
        stack.stack = (int*)realloc(stack.stack, stack.current_size*sizeof(int));
    }
    stack.stack[stack.p++] = v;
}

int pop(stack_a stack){
    return stack.stack[--stack.p];
}

stack_a stack_init(int size){
    stack_a stack;
    stack.current_size = 0;
    stack.chunk_size = 25;

    if(size <= 0)
        return;
    stack.stack = (int*)malloc(size*sizeof(int));
    stack.p = 0;
    stack.current_size += size;
}

void stack_deinit(stack_a stack){
    stack.p = 0;
    free(stack.stack);
}

int is_empty(stack_a stack){
    return !stack.p;
}
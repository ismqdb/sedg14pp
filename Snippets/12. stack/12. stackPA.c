/* ******************************************************************************** */

#include "./12. stackPA.h"

/* ******************************************************************************** */

struct stackPA stackPAInit(int size){
    struct stackPA stack;

    stack.key_array = malloc(size*sizeof(node*));
    stack.next = (int*)malloc(size*sizeof(int));

    stack.head = 0;
    stack.tail = 1;
    stack.current = 2;

    stack.next[stack.head] = stack.tail;
    stack.next[stack.tail] = stack.tail;

    return stack;
}

/* ******************************************************************************** */

void stackPAPushInt(struct stackPA *stack, int v){
    node *new = nodeAllocInt(v);
    stack->key_array[stack->current] = new;

    stack->next[stack->current] = stack->next[stack->head];
    stack->next[stack->head] = stack->current;

    stack->current++;
}

/* ******************************************************************************** */

int stackPAIsEmpty(struct stackPA *stack){
    return stack->current == 2;
}

/* ******************************************************************************** */

node* stackPAPopNode(struct stackPA *stack){
    if(stackPAIsEmpty(stack))
        return NULL;

    node *ret = stack->key_array[stack->next[stack->head]];

    stack->current = stack->next[stack->head];
    stack->next[stack->head] = stack->next[stack->current];
    stack->next[stack->current] = 0;

    return ret;
}

/* ******************************************************************************** */

void stackPADeinit(struct stackPA *stack){
    stack->next[stack->head] = 0;
    stack->next[stack->tail] = 0;

    stack->head = 0;
    stack->tail = 0;
    stack->current = 0;

    free(stack->key_array);
}

/* ******************************************************************************** */
/* ******************************************************************************** */

#include "./11. stack_ll.h"

/* ******************************************************************************** */

stack_ll stack_ll_init(){
    stack_ll stack;
    
    stack.head = nodeAlloc();
    stack.tail = nodeAlloc();

    stack.head->next = stack.tail;
    stack.head->key = 0;
    stack.tail->next = stack.tail;

    return stack;
}

/* ******************************************************************************** */

void stack_ll_push_int(stack_ll stack, int v){
    node *t = nodeAlloc();
    t->key = v;
    t->next = stack.head->next;
    stack.head->next = t; 
}

/* ******************************************************************************** */

int stack_ll_pop_int(stack_ll stack){
    int x;
    node *t = stack.head->next;
    stack.head->next = t->next;
    x = t->key;
    free(t);
    return x;
}

/* ******************************************************************************** */

int stack_ll_is_empty(stack_ll stack){
    return stack.head->next == stack.tail;
}

/* ******************************************************************************** */
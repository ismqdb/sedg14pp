#include <stdio.h>
#include <ctype.h>

#include "../array.c"
#include "./Includes/node.c"

typedef struct stack_ll {
    node *head;
    node *tail;
} stack_ll;

stack_ll stack_init(){
    stack_ll stack;
    
    stack.head = n_alloc();
    stack.tail = n_alloc();

    stack.head->next = stack.tail;
    stack.head->key = 0;
    stack.tail->next = stack.tail;

    return stack;
}

void push(stack_ll stack, int v){
    node *t = n_alloc();
    t->key = v;
    t->next = stack.head->next;
    stack.head->next = t; 
}

int pop(stack_ll stack){
    int x;
    node *t = stack.head->next;
    stack.head->next = t->next;
    x = t->key;
    free(t);
    return x;
}

int is_empty(stack_ll stack){
    return stack.head->next == stack.tail;
}
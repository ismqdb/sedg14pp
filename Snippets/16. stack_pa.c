#include <stdio.h>
#include <stdlib.h>

#include "./Includes/node.c"

typedef struct stack_pa {
    node **key_array;
    int *next;
    int current, head, tail;
} stack_pa;

node* n_alloc(){
    return (node*)malloc(sizeof(node*));
}

node* nalloc_i(int value){
    node *n = (node*)malloc(sizeof(node*));
    n->key = value;
    return n;
}

stack_pa stack_pa_init(int size){
    stack_pa stack;

    stack.key_array = malloc(size*sizeof(node*));
    stack.next = (int*)malloc(size*sizeof(int));

    stack.head = 0;
    stack.tail = 1;
    stack.current = 2;

    stack.next[stack.head] = stack.tail;
    stack.next[stack.tail] = stack.tail;

    return stack;
}

void push(stack_pa stack, int v){
    node *new = nalloc_i(v);
    stack.key_array[stack.current] = new;

    stack.next[stack.current] = stack.next[stack.head];
    stack.next[stack.head] = stack.current;

    stack.current++;
}

int is_empty(stack_pa stack){
    return stack.current == 2;
}

node* pop(stack_pa stack){
    if(is_empty(stack))
        return NULL;

    node *ret = stack.key_array[stack.next[stack.head]];

    stack.current = stack.next[stack.head];
    stack.next[stack.head] = stack.next[stack.current];
    stack.next[stack.current] = 0;

    return ret;
}

void stack_deinit(stack_pa stack){
    stack.next[stack.head] = 0;
    stack.next[stack.tail] = 0;

    stack.head = 0;
    stack.tail = 0;
    stack.current = 0;

    free(stack.key_array);
}

int main(){
    int stack_size = 250;

    stack_pa stack = stack_pa_init(stack_size);

    for(int i = 0; i < stack_size; i++)
        push(stack, i*10);

    for(int i = 0; i < stack_size; i++)
        printf("%d\n", pop(stack)->key);

    stack_deinit(stack);

    putchar(10);
}
#include <stdlib.h>

#include "./Includes/tree_node.c"

typedef struct stack_a {
    data_type type;
    union {
        int* integer;
        tree_node** t_node;
    } data;
    int p;
    int current_size;
    int chunk_size;
} stack_a;

void push_int(stack_a *stack, int v){
    if(stack->p == stack->current_size){
        stack->current_size += stack->chunk_size;
        stack->data.integer = (int*)realloc(stack->data.integer, stack->current_size*sizeof(int));
    }
    stack->data.integer[stack->p++] = v;
}

void push_t_node(stack_a *stack, tree_node* t_node){
    if(stack->p == stack->current_size){
        stack->current_size += stack->chunk_size;
        stack->data.t_node = (tree_node**)realloc(stack->data.t_node, stack->current_size*sizeof(tree_node));
    }
    stack->data.t_node[stack->p++] = t_node;
}

int pop_int(stack_a *stack){
    return stack->data.integer[--stack->p];
}

tree_node* pop_t_node(stack_a *stack){
    return stack->data.t_node[--stack->p];
}

stack_a stack_init(data_type type, int size){
    stack_a stack;
    stack.current_size = 0;
    stack.chunk_size = 25;
    stack.type = type;

    switch(type){
        case INT:
            stack.data.integer = (int*)malloc(size*sizeof(int));
            break;
        case TREE_NODE:
            stack.data.t_node = (tree_node**)malloc(size*sizeof(tree_node));
            break;
    }

    stack.p = 0;
    stack.current_size += size;

    return stack;
}

void stack_deinit(stack_a stack){
    stack.p = 0;

    switch(stack.type){
        case INT:
            free(stack.data.integer);
            break;
        case TREE_NODE:
            free(stack.data.t_node);
            break;
    }
}

int is_empty(stack_a stack){
    return !stack.p;
}
/* ******************************************************************************** */

#include "./12. stack_a.h"

/* ******************************************************************************** */

void stack_a_push_int(stack_a *stack, int v){
    if(stack->p == stack->current_size){
        stack->current_size += stack->chunk_size;
        stack->data.integer = (int*)realloc(stack->data.integer, stack->current_size*sizeof(int));
    }
    stack->data.integer[stack->p++] = v;
}

/* ******************************************************************************** */

void stack_a_push_tree_node(stack_a *stack, tree_node* t_node){
    if(stack->p == stack->current_size){
        stack->current_size += stack->chunk_size;
        stack->data.tree_node = (tree_node**)realloc(stack->data.tree_node, stack->current_size*sizeof(tree_node));
    }
    stack->data.tree_node[stack->p++] = t_node;
}

/* ******************************************************************************** */

int stack_a_pop_int(stack_a *stack){
    return stack->data.integer[--stack->p];
}

/* ******************************************************************************** */

tree_node* stack_a_pop_tree_node(stack_a *stack){
    return stack->data.tree_node[--stack->p];
}

/* ******************************************************************************** */

stack_a stack_a_init(data_type type, int size){
    stack_a stack;
    stack.current_size = 0;
    stack.chunk_size = 25;
    stack.type = type;

    switch(type){
        case INT:
            stack.data.integer = (int*)malloc(size*sizeof(int));
            break;
        case TREE_NODE:
            stack.data.tree_node = (tree_node**)malloc(size*sizeof(tree_node));
            break;
    }

    stack.p = 0;
    stack.current_size += size;

    return stack;
}

/* ******************************************************************************** */

void stack_a_deinit(stack_a *stack){
    stack->p = 0;

    switch(stack->type){
        case INT:
            free(stack->data.integer);
            break;
        case TREE_NODE:
            free(stack->data.tree_node);
            break;
    }
}

/* ******************************************************************************** */

int stack_a_is_empty(stack_a *stack){
    return !stack->p;
}

/* ******************************************************************************** */
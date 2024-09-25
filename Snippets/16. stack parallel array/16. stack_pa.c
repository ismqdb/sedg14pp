#include "./16. stack_pa.h"

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

void stack_pa_push(stack_pa *stack, int v){
    node *new = node_alloc_int(v);
    stack->key_array[stack->current] = new;

    stack->next[stack->current] = stack->next[stack->head];
    stack->next[stack->head] = stack->current;

    stack->current++;
}

int stack_pa_is_empty(stack_pa *stack){
    return stack->current == 2;
}

node* stack_pa_pop(stack_pa *stack){
    if(stack_pa_is_empty(stack))
        return NULL;

    node *ret = stack->key_array[stack->next[stack->head]];

    stack->current = stack->next[stack->head];
    stack->next[stack->head] = stack->next[stack->current];
    stack->next[stack->current] = 0;

    return ret;
}

void stack_pa_deinit(stack_pa *stack){
    stack->next[stack->head] = 0;
    stack->next[stack->tail] = 0;

    stack->head = 0;
    stack->tail = 0;
    stack->current = 0;

    free(stack->key_array);
}

int stack_pa_main(){
    int stack_size = 250;

    stack_pa stack = stack_pa_init(stack_size);

    for(int i = 0; i < stack_size; i++)
        stack_pa_push(&stack, i*10);

    for(int i = 0; i < stack_size; i++)
        printf("%d\n", stack_pa_pop(&stack)->key);

    stack_pa_deinit(&stack);

    putchar(10);
}
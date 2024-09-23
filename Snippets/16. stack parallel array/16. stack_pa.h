#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "../00. Includes/node/node.h"

typedef struct stack_pa {
    node **key_array;
    int *next;
    int current, head, tail;
} stack_pa;

stack_pa stack_pa_init(int);
void stack_pa_push(stack_pa*, int);
int stack_pa_is_empty(stack_pa*);
node* stack_pa_pop(stack_pa*);
void stack_pa_deinit(stack_pa*);
int stack_pa_main();
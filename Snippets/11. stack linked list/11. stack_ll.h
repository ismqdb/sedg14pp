#pragma once

#include <stdio.h>
#include <ctype.h>

#include "../00. Includes/array/array.h"
#include "../00. Includes/node/node.h"

typedef struct stack_ll {
    node *head;
    node *tail;
} stack_ll;

stack_ll stack_ll_init();
void stack_ll_push_int(stack_ll, int);
int stack_ll_pop_int(stack_ll);
int stack_ll_is_empty(stack_ll);
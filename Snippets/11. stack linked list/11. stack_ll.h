#pragma once

#include <stdio.h>
#include <ctype.h>

#include "../00. Includes/array/array.h"
#include "../00. Includes/node/node.h"

typedef struct stack_ll {
    node *head;
    node *tail;
} stack_ll;

stack_ll stack_init();
void push(stack_ll, int);
int pop(stack_ll);
int is_empty(stack_ll);
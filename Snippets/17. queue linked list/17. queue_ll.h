#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "../00. Includes/node/node.h"

typedef struct queue_a {
    node *head;
} queue_a;

queue_a queue_ll_init();
void queue_ll_put(queue_a*, int);
node* queue_ll_get(queue_a*);
int is_queue_ll_empty(queue_a*);
int queue_ll_main();
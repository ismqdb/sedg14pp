#pragma once

#include <stdlib.h>

#include "../00. Includes/tree node/tree_node.h"

typedef struct queue_a {
    data_type type;
    union {
        int* integer;
        tree_node** t_node;
    } data;
    int head;
    int tail;
    int chunk_size;
    int current_size;
} queue_a;

void put_int(queue_a*, int);
void put_tree_node(queue_a*, tree_node*);
int get_int(queue_a*);
tree_node* get_tree_node(queue_a*);
queue_a queue_init(data_type, int);
int is_queue_empty(queue_a*);
void queue_deinit(queue_a*);
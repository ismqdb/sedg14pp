#pragma once

#include <stdlib.h>

#include "../00. includes/tree_node_data_type.h"
#include "../00. includes/tree node/tree_node.h"
#include "../00. includes/tree node right sibling/tree_node_rs.h"

typedef struct queue_a {
    data_type type;
    union {
        int* integer;
        tree_node **tree_node;
        tree_node_rs **tree_node_rs;
    } data;
    int head;
    int tail;
    int chunk_size;
    int current_size;
} queue_a;

void queue_a_put_int(queue_a*, int);
void queue_a_put_tree_node(queue_a*, tree_node*);
void queue_a_put_tree_node_rs(queue_a*, tree_node_rs*);

int queue_a_get_int(queue_a*);
tree_node* queue_a_get_tree_node(queue_a*);
tree_node_rs* queue_a_get_tree_node_rs(queue_a*);

queue_a queue_a_init(data_type, int);
int queue_a_is_empty(queue_a*);
void queue_a_deinit(queue_a*);
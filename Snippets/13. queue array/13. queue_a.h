/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdlib.h>

/* ******************************************************************************** */

#include "../00. includes/treeNodeDataType.h"
#include "../00. includes/tree node/tree_node.h"
#include "../00. includes/tree node rs/tree_node_rs.h"

/* ******************************************************************************** */

typedef struct queue_a {
    treeNodeDataType type;
    union {
        int* integer;
        struct tree_node **tree_node;
        struct tree_node_rs **tree_node_rs;
    } data;
    int head;
    int tail;
    int chunk_size;
    int current_size;
} queue_a;

/* ******************************************************************************** */

void queue_a_put_int(queue_a*, int);
void queue_a_put_tree_node(queue_a*, struct tree_node*);
void queue_a_put_tree_node_rs(queue_a*, struct tree_node_rs*);

/* ******************************************************************************** */

int queue_a_get_int(queue_a*);
struct tree_node* queue_a_get_tree_node(queue_a*);
struct tree_node_rs* queue_a_get_tree_node_rs(queue_a*);

/* ******************************************************************************** */

queue_a queue_a_init(treeNodeDataType, int);
int queue_a_is_empty(queue_a*);
void queue_a_deinit(queue_a*);

/* ******************************************************************************** */
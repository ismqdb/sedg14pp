/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdlib.h>

/* ******************************************************************************** */

#include "../00. includes/treeNodeDataType.h"
#include "../00. includes/tree node/treeNode.h"
#include "../00. includes/tree node RS/treeNodeRS.h"

/* ******************************************************************************** */

typedef struct queue_a {
    treeNodeDataType type;
    union {
        int* integer;
        struct treeNode **treeNode;
        struct tree_node_rs **tree_node_rs;
    } data;
    int head;
    int tail;
    int chunk_size;
    int current_size;
} queue_a;

/* ******************************************************************************** */

void queue_a_put_int(queue_a*, int);
void queue_a_put_tree_node(queue_a*, struct treeNode*);
void queue_a_put_tree_node_rs(queue_a*, struct tree_node_rs*);

/* ******************************************************************************** */

int queue_a_get_int(queue_a*);
struct treeNode* queue_a_get_tree_node(queue_a*);
struct tree_node_rs* queue_a_get_tree_node_rs(queue_a*);

/* ******************************************************************************** */

queue_a queue_a_init(treeNodeDataType, int);
int queue_a_is_empty(queue_a*);
void queue_a_deinit(queue_a*);

/* ******************************************************************************** */
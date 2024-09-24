#include "./13. queue_a.h"

void queue_a_put_int(queue_a *queue, int v){
    if(queue->tail == queue->current_size){
        queue->current_size += queue->chunk_size;
        queue->data.integer = (int*)realloc(queue->data.integer, queue->current_size*sizeof(int));
    }
    queue->data.integer[queue->tail++] = v;
}

void queue_a_put_tree_node(queue_a *queue, tree_node *v){
    if(queue->tail == queue->current_size){
        queue->current_size += queue->chunk_size;
        queue->data.t_node = (tree_node**)realloc(queue->data.t_node, queue->current_size*sizeof(tree_node));
    }
    queue->data.t_node[queue->tail++] = v;
}

int queue_a_get_int(queue_a *queue){
    int t = queue->data.integer[queue->head++];
    if(queue->head == queue->tail){
        queue->head = 0;
        queue->tail = 0;
    }
    return t;
}

tree_node* queue_a_get_tree_node(queue_a *queue){
    tree_node *t = queue->data.t_node[queue->head++];
    if(queue->head == queue->tail){
        queue->head = 0;
        queue->tail = 0;
    }
    return t;
}

queue_a queue_a_init(data_type type, int size){
    queue_a queue;
    queue.chunk_size = 25;
    queue.current_size = 0;
    queue.type = type;

    queue.current_size = size;

    switch(type){
        case INT:
            queue.data.integer = (int*)malloc(queue.current_size*sizeof(int));
            break;
        case TREE_NODE:
            queue.data.t_node = (tree_node**)malloc(queue.current_size*sizeof(tree_node));
            break;
    }

    queue.head = 0;
    queue.tail = 0;
    return queue;
}

int queue_a_is_empty(queue_a *queue){
    return queue->head == queue->tail;
}

void queue_a_deinit(queue_a *queue){
    queue->head = 0;
    queue->tail = 0;

    switch(queue->type){
        case INT:
            free(queue->data.integer);
            break;
        case TREE_NODE:
            free(queue->data.t_node);
            break;
    }
}
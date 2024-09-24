#include "./17. queue_ll.h"

queue_a queue_ll_init(){
    queue_a queue;
    queue.head = NULL;

    return queue;
}

void queue_ll_put(queue_a *queue, int value){
    node *item = n_alloc(value);
    node **p = &queue->head;

    if(queue->head == NULL){
        queue->head = item;
        return;
    }

    while((*p) != NULL)
        //*p = (*p)->next;
        p = &(*p)->next;

    (*p) = item;
}

node* queue_ll_get(queue_a *queue){
    node *item = queue->head;

    queue->head = queue->head->next;
    return item;
}

int queue_ll_is_empty(queue_a *queue){
    return queue->head == NULL;
}

int queue_ll_main(){
    queue_a queue = queue_ll_init();

    int size = 5;

    for(int i = 0; i < size; i++)
        queue_ll_put(&queue, i*i);

    for(int i = 0; i < size; i++)
        printf("%d\n", queue_ll_get(&queue)->key);

    printf("%s\n", queue_ll_is_empty(&queue) ? "Queue is empty." : "Queue is not empty.");

    putchar(10);
}
#include <stdio.h>
#include <stdlib.h>

#include "./Includes/node.c"

typedef struct queue_a {
    node *head;
} queue_a;

queue_a queue_ll_init(){
    queue_a queue;
    queue.head = NULL;

    return queue;
}

void put(queue_a queue, int value){
    node *item = n_alloc(value);
    node **p = &queue.head;

    if(queue.head == NULL){
        queue.head = item;
        return;
    }

    while((*p) != NULL)
        //*p = (*p)->next;
        p = &(*p)->next;

    (*p) = item;
}

node* get(queue_a queue){
    node *item = queue.head;

    queue.head = queue.head->next;
    return item;
}

int is_queue_empty(queue_a queue){
    return queue.head == NULL;
}

int main(){
    queue_a queue = queue_ll_init();

    int size = 5;

    for(int i = 0; i < size; i++)
        put(queue, i*i);

    for(int i = 0; i < size; i++)
        printf("%d\n", get(queue)->key);

    printf("%s\n", is_queue_empty(queue) ? "Queue is empty." : "Queue is not empty.");

    putchar(10);
}
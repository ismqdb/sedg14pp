#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    node *next;
} node;

typedef struct queue_ll {
    node *head;
} queue_ll;

node* n_alloc(int value){
    node *l = (node*)malloc(sizeof(node));
    l->value = value;
    return l;
}


queue_ll queue_ll_init(){
    queue_ll queue;
    queue.head = NULL;

    return queue;
}

void put(queue_ll queue, int value){
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

node* get(queue_ll queue){
    node *item = queue.head;

    queue.head = queue.head->next;
    return item;
}

int is_queue_empty(queue_ll queue){
    return queue.head == NULL;
}

int main(){
    queue_ll queue = queue_ll_init();

    int size = 5;

    for(int i = 0; i < size; i++)
        put(queue, i*i);

    for(int i = 0; i < size; i++)
        printf("%d\n", get(queue)->value);

    printf("%s\n", is_queue_empty(queue) ? "Queue is empty." : "Queue is not empty.");

    putchar(10);
}
#include <stdio.h>
#include <stdlib.h>

struct list_item {
    int value;
    struct list_item *next;
};

struct list {
    struct list_item *head;
};

struct list *list;

struct list* list_alloc(){
    return (struct list*)malloc(sizeof(struct list));
}

struct list_item* list_item_alloc(int value){
    struct list_item *l = (struct list_item*)malloc(sizeof(struct list_item));
    l->value = value;
    return l;
}


void queue_init(){
    list = list_alloc();
    list->head = NULL;
}

void put(int value){
    struct list_item *item = list_item_alloc(value);
    struct list_item **p = &list->head;

    if(list->head == NULL){
        list->head = item;
        return;
    }

    while((*p) != NULL)
        //*p = (*p)->next;
        p = &(*p)->next;

    (*p) = item;
}

struct list_item* get(){
    struct list_item *item = list->head;

    list->head = list->head->next;
    return item;
}

int is_queue_empty(){
    return list->head == NULL;
}

int main(){
    queue_init();

    int size = 5;

    for(int i = 0; i < size; i++)
        put(i*i);

    for(int i = 0; i < size; i++)
        printf("%d\n", get()->value);

    printf("%s\n", is_queue_empty() ? "Queue is empty." : "Queue is not empty.");

    putchar(10);
}
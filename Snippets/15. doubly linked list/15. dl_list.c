/* ******************************************************************************** */

#include "./15. dl_list.h"

/* ******************************************************************************** */

struct nodeDLL* nodeDLLAlloc(){
    return (struct nodeDLL*)malloc(sizeof(struct nodeDLL));
}

/* ******************************************************************************** */

dl_list dl_list_init(){
    dl_list dl_list;

    dl_list.head = nodeDLLAlloc();
    dl_list.tail = nodeDLLAlloc();

    dl_list.head->prev = dl_list.head;
    dl_list.head->next = dl_list.tail;

    dl_list.tail->prev = dl_list.head;
    dl_list.tail->next = dl_list.tail;
}

/* ******************************************************************************** */

void dl_list_deinit(dl_list list){
    free(list.head);
    free(list.tail);
}

/* ******************************************************************************** */

struct nodeDLL* dl_list_insert_after(struct nodeDLL *node, int value){
    struct nodeDLL *new = nodeDLLAlloc();
    new->key = value;

    new->next = node->next;
    node->next = new;
    new->prev = node;

    return new;
}

/* ******************************************************************************** */

void dl_list_remove_next(struct nodeDLL *node){
    node->next = node->next->next;
    node->next->prev = node;
}

/* ******************************************************************************** */
#include "./15. dl_list.h"

dl_list dl_list_init(){
    dl_list dl_list;

    dl_list.head = dl_list_alloc();
    dl_list.tail = dl_list_alloc();

    dl_list.head->prev = dl_list.head;
    dl_list.head->next = dl_list.tail;

    dl_list.tail->prev = dl_list.head;
    dl_list.tail->next = dl_list.tail;
}

void dl_list_deinit(dl_list list){
    free(list.head);
    free(list.tail);
}

dll_node* dl_list_insert_after(dll_node *node, int value){
    dll_node *new = dl_list_alloc();
    new->key = value;

    new->next = node->next;
    node->next = new;
    new->prev = node;

    return new;
}

void dl_list_remove_next(dll_node *node){
    node->next = node->next->next;
    node->next->prev = node;
}
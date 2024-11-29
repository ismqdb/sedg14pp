/* ******************************************************************************** */

#include "./09. linked_list.h"

/* ******************************************************************************** */

linked_list list_initialize(){
    linked_list list;

    list.head = nodeAlloc();
    list.z = nodeAlloc();

    list.head->next = list.z;
    list.z->next = list.z;

    return list;
}

/* ******************************************************************************** */

void delete_next(node *t){
    node *x = t->next;
    t->next = t->next->next;
    nodeDealloc(x);
}

/* ******************************************************************************** */

node* insert_after(int v, node *t){
    if(t == NULL)
        return NULL;

    node *x = nodeAlloc();
    x->key = v;
    x->next = t->next;
    t->next = x;
    return x;
}

/* ******************************************************************************** */

node* move_next_to_front(linked_list list, node *t){
    node *temp = t->next;
    t->next = t->next->next;
    
    temp->next = list.head->next;
    list.head->next = temp;
    return temp;
}

/* ******************************************************************************** */

void exchange(node *t, node *u){
    node *temp = t->next;
    
    t->next = t->next->next;
    temp->next = u->next->next;
    
    u->next->next = t->next;
    t->next = u->next;

    u->next = temp;
}

/* ******************************************************************************** */
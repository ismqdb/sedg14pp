/* ******************************************************************************** */

#include "./09. list.h"

/* ******************************************************************************** */

struct list listInit(){
    struct list list;

    list.head = nodeAlloc();
    list.tail = nodeAlloc();

    list.head->next = list.tail;
    list.tail->next = list.tail;

    return list;
}

/* ******************************************************************************** */

void listDeleteNext(node *t){
    node *x = t->next;
    t->next = t->next->next;
    nodeDealloc(x);
}

/* ******************************************************************************** */

node* listInsertAfter(int v, node *t){
    if(t == NULL)
        return NULL;

    node *x = nodeAlloc();
    x->key = v;
    x->next = t->next;
    t->next = x;
    return x;
}

/* ******************************************************************************** */

node* listMoveNextToFront(struct list *list, node *t){
    node *temp = t->next;
    t->next = t->next->next;
    
    temp->next = list->head->next;
    list->head->next = temp;
    return temp;
}

/* ******************************************************************************** */

void listExchange(node *t, node *u){
    node *temp = t->next;
    
    t->next = t->next->next;
    temp->next = u->next->next;
    
    u->next->next = t->next;
    t->next = u->next;

    u->next = temp;
}

/* ******************************************************************************** */
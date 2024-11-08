/* ******************************************************************************** */

#include "./09. linkedList.hpp"

/* ******************************************************************************** */

linkedList::~linkedList(){
    delete(head);
    delete(tail);
}

linkedList::linkedList(){
    this->head = new node{};
    this->tail = new node{};

    head->next = tail;
    tail->next = tail;
}

/* ******************************************************************************** */

void linkedList::deleteNext(struct node *t){
    struct node *x = t->next;
    t->next = t->next->next;
    delete(x);
}

struct node* linkedList::insertAfter(int v, struct node *t){
    if(t == NULL)
        return NULL;

    struct node *x = new node{};
    x->key = v;
    x->next = t->next;
    t->next = x;
    return x;
}

struct node* linkedList::moveNextToFront(struct node *t){
    struct node *temp = t->next;
    t->next = t->next->next;
    
    temp->next = head->next;
    head->next = temp;
    return temp;
}

void linkedList::exchange(struct node *t, struct node *u){
    struct node *temp = t->next;
    
    t->next = t->next->next;
    temp->next = u->next->next;
    
    u->next->next = t->next;
    t->next = u->next;

    u->next = temp;
}

/* ******************************************************************************** */
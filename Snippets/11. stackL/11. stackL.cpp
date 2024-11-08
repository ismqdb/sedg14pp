/* ******************************************************************************** */

#include "./11. stackL.hpp"

/* ******************************************************************************** */

stackL::stackL(){
    head = new node{};
    tail = new node{};

    head->next = tail;
    head->key = 0;
    tail->next = tail;
}

stackL::~stackL(){
    delete(head);
    delete(tail);
}

/* ******************************************************************************** */

void stackL::push(int v){
    struct node *t = new node{v};
    t->key = v;
    t->next = head->next;
    head->next = t; 

    t = NULL;
    delete(t);
}

void stackL::pop(){
    head->next = head->next->next;
}

struct node* stackL::top(){
    return head->next;
}

/* ******************************************************************************** */

bool stackL::isEmpty(){
    return head->next == tail;
}

/* ******************************************************************************** */
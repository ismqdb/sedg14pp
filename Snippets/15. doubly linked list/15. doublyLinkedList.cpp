/* ******************************************************************************** */

#include "./15. doublyLinkedList.hpp"

/* ******************************************************************************** */

doublyLinkedList::doublyLinkedList(){
    head->prev = head;
    head->next = tail;

    tail->prev = head;
    tail->next = tail;
}

doublyLinkedList::~doublyLinkedList(){
    delete(head);
    delete(tail);
}

/* ******************************************************************************** */

node* doublyLinkedList::insertAfter(node *existingNode, int value){
    node *newNode = new node{value};
    newNode->key = value;

    newNode->next = existingNode->next;
    existingNode->next = newNode;
    newNode->prev = existingNode;

    return newNode;
}

void doublyLinkedList::removeNext(node *node){
    node->next = node->next->next;
    node->next->prev = node;
}

/* ******************************************************************************** */
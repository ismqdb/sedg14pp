/* ******************************************************************************** */

#include <iostream>
#include <vector>

/* ******************************************************************************** */

struct node {
    public:
        node(int val) : key(val), prev{NULL}, next{NULL}{}
        node() : key{0}, prev{NULL}, next{NULL}{}

        int key;
        struct node *prev;
        struct node *next;
};

/* ******************************************************************************** */

class doublyLinkedList {
    public:
        doublyLinkedList();
        ~doublyLinkedList();

        node* insertAfter(node*, int);
        void removeNext(node*);
    private:
        node *head;
        node *tail;
};

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

int main(){
    doublyLinkedList list{};
}

/* ******************************************************************************** */
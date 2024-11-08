/* ******************************************************************************** */

#pragma once

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
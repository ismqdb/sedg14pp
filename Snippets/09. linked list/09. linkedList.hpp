/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

/* ******************************************************************************** */

struct node {
    public:
        node(int val) : key{val}, next{NULL}{}
        node() : key{0}, next{NULL}{}

        int key;
        struct node *next;
};

/* ******************************************************************************** */

class linkedList {
    public:
        linkedList();
        ~linkedList();

        void deleteNext(struct node*);
        struct node* insertAfter(int, struct node*);
        struct node* moveNextToFront(struct node*);
        void exchange(struct node*, struct node*);
    private:
        struct node* head;
        struct node* tail;
};

/* ******************************************************************************** */
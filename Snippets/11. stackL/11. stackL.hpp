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

class stackL {
    public:
        stackL();
        ~stackL();

        void push(int v);
        void pop();
        struct node* top();
        bool isEmpty();
    private:
        node *head;
        node *tail;
};

/* ******************************************************************************** */
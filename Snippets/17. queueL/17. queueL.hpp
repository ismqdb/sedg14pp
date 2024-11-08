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

class queueL {
    public:
        queueL();
        ~queueL();

        void put(int);
        node* get();
        bool isEmpty();
    private:
        node *head;
        node *current;
};

/* ******************************************************************************** */
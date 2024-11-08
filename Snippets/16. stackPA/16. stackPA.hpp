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

class stackPA {
    public:
        stackPA();
        ~stackPA();

        void push(int);
        struct node* top();
        void pop();
        bool isEmpty();
    private:
        std::vector<node*> storage;
        std::vector<int> next;
        int current;
        int head;
        int tail;
};

/* ******************************************************************************** */
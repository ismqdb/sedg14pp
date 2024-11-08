/* ******************************************************************************** */

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

int main(){
    stackL stack{};

    stack.push(3);
    stack.push(4);
    stack.push(5);

    stack.pop();
    stack.pop();
    stack.pop();

    putchar(10);
}

/* ******************************************************************************** */
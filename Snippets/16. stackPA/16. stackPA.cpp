/* ******************************************************************************** */

#include "./16. stackPA.hpp"

/* ******************************************************************************** */

stackPA::stackPA(){
    next = std::vector<int>(2);
    storage = std::vector<node*>(2);

    head = 0;
    tail = 1;
    current = 2;

    next[head] = tail;
    next[tail] = tail;
}

stackPA::~stackPA(){
    next[head] = 0;
    next[tail] = 0;

    head = 0;
    tail = 0;
    current = 0;

    this->storage.clear();
    this->next.clear();
}

/* ******************************************************************************** */

void stackPA::push(int v){
    if(storage.capacity() == current){
        this->storage.resize(storage.capacity() + 10);
        this->next.resize(this->next.capacity() + 10);
    }

    struct node *nodeToInsert = new node(v);
    storage[current] = nodeToInsert;

    next[current] = next[head];
    next[head] = current;

    current++;
}

node* stackPA::top(){
    return storage[next[head]];
}

void stackPA::pop(){
    if(isEmpty())
        throw;

    current = next[head];
    next[head] = next[current];

    storage.erase(storage.begin() + current);
    next.erase(next.begin() + current);
}

/* ******************************************************************************** */

bool stackPA::isEmpty(){
    return current == 2;
}

/* ******************************************************************************** */
/* ******************************************************************************** */

#include "./16. stackPA.hpp"

/* ******************************************************************************** */

template<typename T>
    stackPA<T>::stackPA(){
        next = std::vector<int>(2);
        storage = std::vector<node<T>*>(2);

        head = 0;
        tail = 1;
        current = 2;

        next[head] = tail;
        next[tail] = tail;
    }

template<typename T>
    stackPA<T>::~stackPA(){
        next[head] = 0;
        next[tail] = 0;

        head = 0;
        tail = 0;
        current = 0;

        this->storage.clear();
        this->next.clear();
    }

/* ******************************************************************************** */

template<typename T>
    void stackPA<T>::push(int v){
        if(storage.capacity() == current){
            this->storage.resize(storage.capacity() + 10);
            this->next.resize(this->next.capacity() + 10);
        }

        node<T> *nodeToInsert = new node<T>(v);
        storage[current] = nodeToInsert;

        next[current] = next[head];
        next[head] = current;

        current++;
    }

template<typename T>
    node<T>* stackPA<T>::top(){
        return storage[next[head]];
    }

template<typename T>
    void stackPA<T>::pop(){
        if(isEmpty())
            throw;

        current = next[head];
        next[head] = next[current];

        storage.erase(storage.begin() + current);
        next.erase(next.begin() + current);
    }

/* ******************************************************************************** */

template<typename T>
    bool stackPA<T>::isEmpty(){
        return current == 2;
    }

/* ******************************************************************************** */
/* ******************************************************************************** */

#include "./11. stackL.hpp"

/* ******************************************************************************** */

template<typename T>
    stackL<T>::stackL(){
        head = new T{};
        tail = new T{};

        head->next = tail;
        head->key = 0;
        tail->next = tail;
    }

template<typename T>
    stackL<T>::~stackL(){
        delete(head);
        delete(tail);
    }

/* ******************************************************************************** */

template<typename T>
    void stackL<T>::push(T v){
        T *t = new T{v};
        t->key = v;
        t->next = head->next;
        head->next = t; 

        t = NULL;
        delete(t);
    }

template<typename T>
    void stackL<T>::pop(){
        head->next = head->next->next;
    }

template<typename T>
    T* stackL<T>::top(){
        return head->next;
    }

/* ******************************************************************************** */

template<typename T>
    bool stackL<T>::isEmpty(){
        return head->next == tail;
    }

/* ******************************************************************************** */
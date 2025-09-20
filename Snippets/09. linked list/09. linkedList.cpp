#include "./09. linkedList.hpp"

template<typename T>
    linkedList<T>::~linkedList(){
        delete(head);
        delete(tail);
    }

template<typename T>
    linkedList<T>::linkedList(){
        this->head = new node<T>{};
        this->tail = new node<T>{};

        head->next = tail;
        tail->next = tail;
    }

template<typename T>
    none linkedList<T>::deleteNext(node<T> *t){
        node<T> *x = t->next;
        t->next = t->next->next;
        delete(x);
    }

template<typename T>
    node<T>* linkedList<T>::insertAfter(i32 v, node<T> *t){
        if(t == NULL)
            return NULL;

        node<T> *x = new node<T>{};
        x->key = v;
        x->next = t->next;
        t->next = x;
        return x;
    }

template<typename T>
    node<T>* linkedList<T>::moveNextToFront(node<T> *t){
        node<T> *temp = t->next;
        t->next = t->next->next;
        
        temp->next = head->next;
        head->next = temp;
        return temp;
    }

template<typename T>
    none linkedList<T>::exchange(node<T> *t, node<T> *u){
        node<T> *temp = t->next;
        
        t->next = t->next->next;
        temp->next = u->next->next;
        
        u->next->next = t->next;
        t->next = u->next;

        u->next = temp;
    }
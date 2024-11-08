/* ******************************************************************************** */

#include "./17. queueL.hpp"

/* ******************************************************************************** */

template<typename T>
    queueL<T>::queueL(){
        this->head = NULL;
        this->current = NULL;
    }

template<typename T>
    queueL<T>::~queueL(){

    }

/* ******************************************************************************** */

template<typename T>
    void queueL<T>::put(int value){
        node<T> *item = new node<T>{value};

        if(this->head == NULL){
            this->head = item;
            this->current = this->head;
            return;
        }

        current->next = item;
        current = current->next;

        item = NULL;
        delete(item);
    }

template<typename T>
    node<T>* queueL<T>::get(){
        node<T> *item = this->head;

        this->head = this->head->next;
        return item;
    }

/* ******************************************************************************** */

template<typename T>
    bool queueL<T>::isEmpty(){
        return this->head == NULL;
    }

/* ******************************************************************************** */
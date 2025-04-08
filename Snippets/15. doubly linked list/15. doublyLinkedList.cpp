/* ******************************************************************************** */

#include "./15. doublyLinkedList.hpp"

/* ******************************************************************************** */

template<typename T>
    doublyLinkedList<T>::doublyLinkedList(){
        head->prev = head;
        head->next = tail;

        tail->prev = head;
        tail->next = tail;
    }

template<typename T>
    doublyLinkedList<T>::~doublyLinkedList(){
        delete(head);
        delete(tail);
    }

/* ******************************************************************************** */

template<typename T>
    node<T>* doublyLinkedList<T>::insertAfter(node<T> *existingNode, i32 value){
        node<T> *newNode = new node<T>{value};
        newNode->key = value;

        newNode->next = existingNode->next;
        existingNode->next = newNode;
        newNode->prev = existingNode;

        return newNode;
    }

template<typename T>
    void doublyLinkedList<T>::removeNext(node<T> *node){
        node->next = node->next->next;
        node->next->prev = node;
    }

/* ******************************************************************************** */
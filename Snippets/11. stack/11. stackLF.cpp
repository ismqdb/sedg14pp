/* ******************************************************************************** */

#include "./11. stackLF.hpp"

/* ******************************************************************************** */

template<typename T>
    stackLF<T>::stackLF(){
        
    }

template<typename T>
    stackLF<T>::~stackLF(){

    }

/* ******************************************************************************** */

template<>
    void stackLF<int>::push(int v){
        node<int>* newNode = new node<int>(v);

        newNode->next = head.load(std::memory_order::relaxed);

        while(!head.compare_exchange_strong(newNode->next, newNode, 
            std::memory_order::release, std::memory_order::relaxed));
    }

template<>
    int& stackLF<int>::top(){
        return head.load()->key;
    }

template<>
    void stackLF<int>::pop(){
        node<int> *newNode = head.load();

        while(!head.compare_exchange_strong(newNode, newNode->next,
        std::memory_order::seq_cst));
    }

/* ******************************************************************************** */

template<typename T>
    void stackLF<T>::pop(){

    }

template<typename T>
    T& stackLF<T>::top(){
        
    }

/* ******************************************************************************** */

template<typename T>
    bool stackLF<T>::isEmpty(){

    }

/* ******************************************************************************** */
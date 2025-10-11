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
    none stackLF<i32>::push(i32 v){
        node<i32>* newNode = new node<i32>(v);

        newNode->next = head.load(std::memory_order::relaxed);

        while(!head.compare_exchange_strong(newNode->next, newNode, 
            std::memory_order::release, std::memory_order::relaxed));
    }

template<>
    i32& stackLF<i32>::top(){
        return head.load()->key;
    }

template<>
    none stackLF<i32>::pop(){
        node<i32> *newNode = head.load();

        while(!head.compare_exchange_strong(newNode, newNode->next,
        std::memory_order::seq_cst));
    }

/* ******************************************************************************** */

template<typename T>
    none stackLF<T>::pop(){

    }

template<typename T>
    T& stackLF<T>::top(){
        
    }

/* ******************************************************************************** */

template<typename T>
    bool stackLF<T>::isEmpty(){
        return false;
    }

/* ******************************************************************************** */
#include "./11. stackPA.hpp"

template<typename T>
    stackPA<T>::stackPA(){
        this->current = 2;
    }

template<typename T>
    stackPA<T>::~stackPA(){
        this->current = 2;
    }

template<typename T>
    none stackPA<T>::push(T v){
        this->data.insertAfter(v, this->current++);
    }

template<typename T>
    T& stackPA<T>::top(){
        return this->data[current-1];
    }

template<typename T>
    none stackPA<T>::pop(){
        if(isEmpty())
            throw;

        this->data.deleteNext(this->current---1);
    }

template<typename T>
    bool stackPA<T>::isEmpty(){
        return this->current == 2;
    }
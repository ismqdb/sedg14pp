/* ******************************************************************************** */

#include "./11. stackL.hpp"

/* ******************************************************************************** */

template<typename T>
    stackL<T>::stackL(){

    }

template<typename T>
    stackL<T>::~stackL(){

    }

/* ******************************************************************************** */

template<typename T>
    none stackL<T>::push(T v){
        this->data.push_back(v);
    }

template<typename T>
    none stackL<T>::pop(){
        this->data.pop_back();
    }

template<typename T>
    T& stackL<T>::top(){
        return this->data.back();
    }

/* ******************************************************************************** */

template<typename T>
    bool stackL<T>::isEmpty(){
        return this->data.empty();
    }

/* ******************************************************************************** */
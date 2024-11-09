/* ******************************************************************************** */

#include "./13. queueL.hpp"

/* ******************************************************************************** */

template<typename T>
    queueL<T>::queueL(){

    }

template<typename T>
    queueL<T>::~queueL(){

    }

/* ******************************************************************************** */

template<typename T>
    void queueL<T>::put(T value){
        this->data.push_back(value);
    }

template<typename T>
    T& queueL<T>::get(){
        return this->data.front();
    }

/* ******************************************************************************** */

template<typename T>
    bool queueL<T>::isEmpty(){
        return this->data.empty();
    }

/* ******************************************************************************** */
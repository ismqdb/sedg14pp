/* ******************************************************************************** */

#include "./13. queueA.hpp"

/* ******************************************************************************** */

template<typename T>
    void queueA<T>::put(T v){
        this->storage.push_back(v);
    }

template<typename T>
    T& queueA<T>::get(){
        int t = storage.front();
        storage.erase(storage.begin());
        return t;
    }

/* ******************************************************************************** */

template<typename T>
    queueA<T>::queueA(){

    }

template<typename T>
    queueA<T>::~queueA(){

    }

/* ******************************************************************************** */

template<typename T>
    bool queueA<T>::isEmpty(){
        return storage.empty();
    }

/* ******************************************************************************** */
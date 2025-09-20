#include "./node.hpp"

template<typename T>
    node<T>::node(T v){
        this->key = v;
        this->next = NULL;
    }

template<typename T>
    node<T>::node(T v, node<T>* n){
        this->key = v;
        this->next = n;
    }
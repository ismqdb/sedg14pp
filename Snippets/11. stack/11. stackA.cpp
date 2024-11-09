/* ******************************************************************************** */

#include "./11. stackA.hpp"

/* ******************************************************************************** */

template<typename T>
    bool stackA<T>::isEmpty(){
        return !p;
    }

/* ******************************************************************************** */

template<typename T>
    void stackA<T>::push(T v){
        this->stack.push_back(v);
        p++;
    }

template<typename T>
    void stackA<T>::pop(){
        if(p > 0){
            p--;
            this->stack.pop_back();
        }
    }

template<typename T>
    T& stackA<T>::top(){
        if(!isEmpty())
            return stack[p-1];
        else
            throw "Top(): empty stack.";
    }

/* ******************************************************************************** */

template<typename T>
    stackA<T>::stackA(){
        p = 0;
    }

template<typename T>
    stackA<T>::~stackA(){
        p = 0;
    }

/* ******************************************************************************** */
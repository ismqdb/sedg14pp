/* ******************************************************************************** */

#include "./11. stackA.hpp"

/* ******************************************************************************** */

template<typename T>
    bool stackA<T>::isEmpty(){
        std::lock_guard<std::mutex> lock(this->mtx);
        return currentIndex <= 0;
    }

/* ******************************************************************************** */

template<typename T>
    void stackA<T>::push(T v){
        std::lock_guard<std::mutex> lock(this->mtx);
        this->stack.push_back(v);
        currentIndex++;
        this->condVar.notify_one();
    }

template<typename T>
    void stackA<T>::pop(){
        std::unique_lock<std::mutex> lock(this->mtx);
        condVar.wait(lock, [this]{return this->currentIndex > -1;});
        currentIndex--;
        this->stack.pop_back();
    }

template<typename T>
    T& stackA<T>::top(){
        if(!isEmpty())
            return std::ref(stack[this->currentIndex-1]);
        else
            throw "Top(): empty stack.";
    }

/* ******************************************************************************** */

template<typename T>
    stackA<T>::stackA(){
        currentIndex = 0;
    }

template<typename T>
    stackA<T>::~stackA(){
        currentIndex = 0;
    }

/* ******************************************************************************** */
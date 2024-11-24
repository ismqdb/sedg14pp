/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <mutex>
#include <condition_variable>

#include "./11. stack.hpp"

/* ******************************************************************************** */

template<typename T>
    class stackA : public stack<T> {
        public:
            stackA();
            ~stackA() override;

            void push(T) override;
            void pop() override;
            T& top() override;

            bool isEmpty() override;
        private:
            std::vector<T> stack;
            int currentIndex;
            std::mutex mtx;
            std::condition_variable condVar;
    };

/* ******************************************************************************** */

template class stackA<int>;
template class stackA<char>;

/* ******************************************************************************** */
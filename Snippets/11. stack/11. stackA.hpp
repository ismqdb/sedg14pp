/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

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
            int p;
    };

/* ******************************************************************************** */

template class stackA<int>;
template class stackA<char>;

/* ******************************************************************************** */
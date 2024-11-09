/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

#include "./11. stack.hpp"

/* ******************************************************************************** */

template<typename T>
    class stackL : public stack<T> {
        public:
            stackL();
            ~stackL() override;

            void push(T) override;
            void pop() override;
            T* top() override;

            bool isEmpty() override;

        private:
            T *head;
            T *tail;
    };

/* ******************************************************************************** */
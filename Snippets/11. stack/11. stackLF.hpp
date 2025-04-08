/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <atomic>

/* ******************************************************************************** */

#include "../00. includes/node/node.hpp"
#include "../00. includes/types.hpp"

#include "./11. stack.hpp"

/* ******************************************************************************** */

template<typename T>
    class stackLF : public stack<T> {
        public:
            stackLF();
            ~stackLF() override;

            void push(T) override;
            void pop() override;
            T& top() override;

            bool isEmpty() override;

        private:
            std::atomic<node<T>*> head;
    };

/* ******************************************************************************** */

template class stackLF<i32>;

/* ******************************************************************************** */
/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#define INL

/* ******************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <mutex>
#include <condition_variable>

/* ******************************************************************************** */

#include "../00. includes/tree node/treeNode.hpp"
#include "./11. stack.hpp"

#include "../00. includes/types.hpp"

/* ******************************************************************************** */

template<typename T>
    class stackA : public stack<T> {
        public:
            stackA();
            ~stackA() override;

            none push(T) override;
            none pop() override;
            T& top() override;

            bool isEmpty() override;
        private:
            std::vector<T> stack;
            i32 currentIndex;
            std::mutex mtx;
            std::condition_variable condVar;
    };

/* ******************************************************************************** */

template class stackA<i32>;
template class stackA<i8>;
template class stackA<treeNode<i8>*>;

/* ******************************************************************************** */
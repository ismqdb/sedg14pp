/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

#include "../00. includes/node/node.hpp"

/* ******************************************************************************** */

template<typename T>
    class stackPA {
        public:
            stackPA();
            ~stackPA();

            void push(int);
            node<T>* top();
            void pop();
            bool isEmpty();
        private:
            std::vector<node<T>*> storage;
            std::vector<int> next;
            int current;
            int head;
            int tail;
    };

/* ******************************************************************************** */
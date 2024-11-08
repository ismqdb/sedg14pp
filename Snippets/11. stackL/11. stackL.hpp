/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

#include "../00. includes/node/node.hpp"

/* ******************************************************************************** */

template<typename T>
    class stackL {
        public:
            stackL();
            ~stackL();

            void push(int v);
            void pop();
            node<T>* top();
            bool isEmpty();
        private:
            node<T> *head;
            node<T> *tail;
    };

/* ******************************************************************************** */
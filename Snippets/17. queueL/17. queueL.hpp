/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

#include "../00. includes/node/node.hpp"

/* ******************************************************************************** */

template<typename T>
    class queueL {
        public:
            queueL();
            ~queueL();

            void put(int);
            node<T>* get();
            bool isEmpty();
        private:
            node<T> *head;
            node<T> *current;
    };

/* ******************************************************************************** */
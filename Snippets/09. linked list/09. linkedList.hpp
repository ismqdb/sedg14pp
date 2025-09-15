/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <iostream>
#include <vector>

/* ******************************************************************************** */

#include "../00. includes/node/node.hpp"
#include "../00. includes/types.hpp"

/* ******************************************************************************** */

template<typename T>
    class linkedList {
        public:
            linkedList();
            ~linkedList();

            none deleteNext(node<T>*);
            node<T>* insertAfter(int, node<T>*);
            node<T>* moveNextToFront(node<T>*);
            none exchange(node<T>*, node<T>*);
        private:
            node<T>* head;
            node<T>* tail;
    };

/* ******************************************************************************** */
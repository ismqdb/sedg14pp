/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

#include "../00. includes/node/node.hpp"

/* ******************************************************************************** */

template<typename T>
    class linkedList {
        public:
            linkedList();
            ~linkedList();

            void deleteNext(node<T>*);
            node<T>* insertAfter(int, node<T>*);
            node<T>* moveNextToFront(node<T>*);
            void exchange(node<T>*, node<T>*);
        private:
            node<T>* head;
            node<T>* tail;
    };

/* ******************************************************************************** */
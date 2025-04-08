/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <iostream>
#include <stddef.h>

/* ******************************************************************************** */

#include "../00. includes/node/node.hpp"
#include "../00. includes/types.hpp"

/* ******************************************************************************** */

template<typename T>
    class linkedList {
        public:
            linkedList();
            ~linkedList();

            size_t size();
            void print();

            void insertBefore(node<T>*, node<T>*);

            void exchange(node<T>*, node<T>*);

            void append(node<T>*);
            void prepend(node<T>*);

            void removeCS101(node<T>*);
            void removeElegant(node<T>*);

        private:
            node<T>** findIndirect(node<T>*);
            node<T>** findIndirectPrev(node<T>*);

            node<T> *head;
            node<T> *cur;
            node<T>* prev;
            i32 currentsize = 0;
    };

/* ******************************************************************************** */
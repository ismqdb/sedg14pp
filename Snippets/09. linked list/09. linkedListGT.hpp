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
            none print();

            none insertBefore(node<T>*, node<T>*);

            none exchange(node<T>*, node<T>*);

            none append(node<T>*);
            none prepend(node<T>*);

            none removeCS101(node<T>*);
            none removeElegant(node<T>*);

        private:
            node<T>** findIndirect(node<T>*);
            node<T>** findIndirectPrev(node<T>*);

            node<T> *head;
            node<T> *cur;
            node<T>* prev;
            i32 currentsize = 0;
    };

/* ******************************************************************************** */
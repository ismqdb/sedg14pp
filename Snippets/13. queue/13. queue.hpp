/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include "../00. includes/types.hpp"

/* ******************************************************************************** */

template<typename T>
    class queue {
        public:
            ~queue(){}

            void put(T) = 0;
            T& get() = 0;
            bool isEmpty() = 0;
    };

/* ******************************************************************************** */
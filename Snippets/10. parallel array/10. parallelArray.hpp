/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

/* ******************************************************************************** */

template<typename T>
    class parallelArray {
        public:
            parallelArray();
            ~parallelArray();

            void deleteNext(int);
            char insertAfter(T, int);
            void printAll();

            bool empty();

            T& operator[](int);
        private:
            std::vector<T> key;
            std::vector<int> next;
            int current;
            int head;
            int tail;
    };

/* ******************************************************************************** */

int parallelArrayDriver();

/* ******************************************************************************** */

template class parallelArray<int>;

/* ******************************************************************************** */
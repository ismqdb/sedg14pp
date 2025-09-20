#pragma once

#include <iostream>
#include <vector>

#include "../00. includes/types.hpp"

template<typename T>
    class parallelArray {
        public:
            parallelArray();
            ~parallelArray();

            none deleteNext(i32);
            i8 insertAfter(T, i32);
            none printAll();

            bool empty();

            T& operator[](i32);
        private:
            std::vector<T> key;
            std::vector<i32> next;
            i32 current;
            i32 head;
            i32 tail;
    };

i32 parallelArrayDriver();

template class parallelArray<i32>;
#pragma once

#include <iostream>
#include <vector>

#include "../00. includes/types.hpp"

#include "./11. stack.hpp"
#include "../10. parallel array/10. parallelArray.hpp"

template<typename T>
    class stackPA : public stack<T> {
        public:
            stackPA();
            ~stackPA() override;

            none push(T) override;
            T& top() override;
            none pop() override;

            bool isEmpty() override;
        private:
            parallelArray<T> data;
            i32 current;
    };

template class stackPA<i32>;
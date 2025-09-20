#pragma once

#include <iostream>
#include <vector>
#include <list>

#include "./11. stack.hpp"
#include "../00. includes/types.hpp"

template<typename T>
    class stackL : public stack<T> {
        public:
            stackL();
            ~stackL() override;

            none push(T) override;
            none pop() override;
            T& top() override;

            bool isEmpty() override;

        private:
            std::list<T> data;
    };

template class stackL<i32>;
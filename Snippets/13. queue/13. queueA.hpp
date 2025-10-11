/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <iostream>
#include <vector>

/* ******************************************************************************** */

#include "../00. includes/types.hpp"

#include "./13. queue.hpp"

/* ******************************************************************************** */

template<typename T>
    class queueA : public queue<T> {
        public:
            queueA();
            ~queueA() override;

            none put(T) override;
            T& get() override;
            bool isEmpty() override;
    private:
        std::vector<i32> storage;
};

/* ******************************************************************************** */
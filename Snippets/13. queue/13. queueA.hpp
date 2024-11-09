/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

#include "./13. queue.hpp"

/* ******************************************************************************** */

template<typename T>
    class queueA : public queue<T> {
        public:
            queueA();
            ~queueA() override;

            void put(T) override;
            T& get() override;
            bool isEmpty() override;
    private:
        std::vector<int> storage;
};

/* ******************************************************************************** */
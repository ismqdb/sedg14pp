/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <list>

#include "./13. queue.hpp"

/* ******************************************************************************** */

template<typename T>
    class queueL : public queue<T> {
        public:
            queueL();
            ~queueL() override;

            void put(T) override;
            T& get() override;
            bool isEmpty() override;
        private:
            std::list<T> data;
    };

/* ******************************************************************************** */
/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

/* ******************************************************************************** */

class stackA {
    public:
        stackA();
        ~stackA();

        void push(int v);
        void pop();
        int top();

        int isEmpty();
    private:
        std::vector<int> stack;
        int p;
};

/* ******************************************************************************** */
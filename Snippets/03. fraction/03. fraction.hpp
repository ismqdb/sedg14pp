/* ******************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

#include "../01. gcd/01. gcd.hpp"

/* ******************************************************************************** */

class fraction {
    public:
        fraction(int num, int denom) : 
            numerator{num}, denominator{denom}{}
        void reduce();
        void print();
    private:
        int numerator;
        int denominator;
};

/* ******************************************************************************** */
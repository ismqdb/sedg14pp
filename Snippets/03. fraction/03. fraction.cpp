/* ******************************************************************************** */

#include "./03. fraction.hpp"

/* ******************************************************************************** */

void fraction::reduce(){
    i32 gcd = gcdMod(this->numerator, this->denominator);

    this->numerator /= gcd;
    this->denominator /= gcd;
}

/* ******************************************************************************** */

void fraction::print(){
    if(numerator != 0 && denominator != 0)
        std::cout << numerator << '/' << denominator << '\n';
    else    
        throw;
}

/* ******************************************************************************** */
/* ******************************************************************************** */

#include <iostream>
#include <future>
#include <thread>

#include "Snippets/08. sieve/08. sieve.hpp"

/* ******************************************************************************** */

int main(){
    sieveResult x = sieveUnbounded();
    sieveResult y = sieveOptimized();

    std::cout << "Sieve: " << x.seconds << "\tseconds, biggest idx: " << x.idx << ".\n";
    std::cout << "Sieve: " << y.seconds << "\tseconds, biggest idx: " << y.idx << ".\n";
}

/* ******************************************************************************** */
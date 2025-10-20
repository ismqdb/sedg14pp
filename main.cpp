/* ******************************************************************************** */

#include <iostream>
#include <future>
#include <thread>
#include <cmath>
#include <vector>

/* ******************************************************************************** */

#include "Snippets/23. sort/23. sort.hpp"
#include "Snippets/23. sort/23. insSort.hpp"

/* ******************************************************************************** */

i32 main(){
    enum {noOfElems = 1000};
    
    i8 in[noOfElems];

    std::vector<ssresult> iterations;

    for (int i = 0; i < noOfElems; i++)
        in[i] = noOfElems - i;

    for (i32 i = 0; i < 64; i++) {
        iterations.push_back(shellSort(in, noOfElems, i));
    }

    std::stable_sort(iterations.begin(), iterations.end(), [](ssresult x, ssresult y) {
        return x.iters < y.iters;
    });

    for (i32 i = 0; i < iterations.size(); i++) {
        std::cout 
            << "h: "
            << iterations[i].h 
            << "\titers: " 
            << iterations[i].iters 
            << '\n';
    }
}

/* ******************************************************************************** */
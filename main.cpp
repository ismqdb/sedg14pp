/* ******************************************************************************** */

#include <iostream>
#include <future>
#include <thread>
#include <cmath>
#include <vector>
#include <functional>

/* ******************************************************************************** */

#include "Snippets/23. sort/23. qsort.hpp"

/* ******************************************************************************** */

i32 main(){
    enum {noOfElems = 10};

    i32 array[noOfElems] = {
        1, 5, 3, 7, 9, 
        10, 11, 0, 9, 2
    };

    qsortRR(array, noOfElems);

    for(i32 i = 0; i < noOfElems; i++)
        std::cout << array[i] << '\n';
}

/* ******************************************************************************** */
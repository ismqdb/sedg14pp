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

i32 main() 
{
    enum {noOfElems = 100};

    i32 array[noOfElems];

    for(i32 i = 0; i < noOfElems; i++)
        array[i] = noOfElems-i;

    qsort(array, 0, noOfElems-1);

    for(i32 i = 0; i < noOfElems; i++)
        std::cout << array[i] << '\n';
}

/* ******************************************************************************** */
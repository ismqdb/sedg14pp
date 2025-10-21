/* ******************************************************************************** */

#include <iostream>
#include <future>
#include <thread>
#include <cmath>
#include <vector>

/* ******************************************************************************** */

#include "Snippets/23. sort/23. dcount.hpp"

/* ******************************************************************************** */

i32 main(){
    enum { noOfElems = 18 };

    i32 elems[noOfElems];

    for (i32 i = 0; i < noOfElems; i++)
        if (i % 2)
            elems[i] = 3;
        else
            elems[i] = 5;

    distrCountBinary(elems, noOfElems);

    for (i32 i = 0; i < noOfElems; i++)
        std::cout << elems[i] << ' ';

    putchar(10);
}

/* ******************************************************************************** */
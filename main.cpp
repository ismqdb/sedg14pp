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
    enum {noOfElems = 18};

    enum {maxKeys = 16};

    i32 elems[noOfElems] = {
        0xA, 0xB, 0xC, 0xD, 0xE, 0xF,
        0xF, 0xE, 0xD, 0xC, 0xB, 0xA,
        0xA, 0xB, 0xC, 0xD, 0xE, 0xF
    };

    distrCount(elems, noOfElems, maxKeys);

    for(i32 i = 0; i < noOfElems; i++)
        std::cout << elems[i] << ' ';

    putchar(10);
}
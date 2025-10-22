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

i32 main() {
    enum { noOfElems = 1000 };

    i8 in[noOfElems];

    for (i32 i = 0; i < noOfElems; i++)
        in[i] = noOfElems - i;

    shellSort(in, noOfElems);
}

/* ******************************************************************************** */
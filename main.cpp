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
    enum {noOfElems = 12};
    
    signed char in[noOfElems] = {
        'E', 'A', 'S', 'Y',
        'Q', 'U', 'E', 'S', 'T', 'I', 'O', 'N'
    };

    shellSort(in, noOfElems, 0);

    for (int i = 0; i < noOfElems; i++)
        std::cout << in[i] << '\n';
}

/* ******************************************************************************** */
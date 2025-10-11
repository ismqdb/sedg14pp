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
    enum {noOfElems = 10};
    
    signed char a[noOfElems];

    for(int i = noOfElems-1; i > -1; i--){
        a[noOfElems-i-1] = i;
    }

    shellSort(a, noOfElems);
}

/* ******************************************************************************** */
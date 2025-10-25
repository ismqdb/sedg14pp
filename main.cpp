/* ******************************************************************************** */

#include <iostream>
#include <future>
#include <thread>
#include <cmath>
#include <vector>
#include <functional>

/* ******************************************************************************** */

#include "Snippets/23. sort/23. shellSort.hpp"

/* ******************************************************************************** */

i32 main() {
    enum { noOfElems = 1000 };
    enum {noOfArrays = 6 };

    i32 in[noOfArrays][noOfElems];

    for(i32 array = 0; array < noOfArrays; array++)
        for (i32 i = 0; i < noOfElems; i++)
            in[array][i] = noOfElems - i;

    std::vector<std::vector<i32>(*)(i32)> pfn{};

    pfn.push_back(shell_seq);
    pfn.push_back(knuth_seq);
    pfn.push_back(hibbard_seq);
    pfn.push_back(sedg_seq_1);
    pfn.push_back(sedg_seq_2);
    pfn.push_back(tokuda_seq);

    for (i32 i = 0; i < noOfArrays; i++) {
        //i32 time = shellSort(in[i], noOfElems, pfn[i]);
        std::cout << time << '\n';
    }
}

/* ******************************************************************************** */
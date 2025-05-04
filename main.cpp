/* ******************************************************************************** */

#include <iostream>
#include <future>
#include <thread>
#include <cmath>

/* ******************************************************************************** */

#include "Snippets/00. includes/rand/rand.hpp"
#include "Snippets/23. sort/23. sort.hpp"

/* ******************************************************************************** */

int main(){
    enum {vecSize = 10};

    std::vector<i32> vec = getRandVec(vecSize, 0, 50);
    
    i32 sortIndexes[vecSize];
    for(int i = 0; i < vecSize; i++)
        sortIndexes[i] = i;

    insitu(vec.data(), sortIndexes, vecSize);

    for(i32 i = 0; i < vecSize; i++)
        std::cout << vec[sortIndexes[i]] << ' ';

    putchar(10);
}

/* ******************************************************************************** */
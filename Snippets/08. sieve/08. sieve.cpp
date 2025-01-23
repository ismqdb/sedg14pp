/* ******************************************************************************** */

#include <iostream>
#include <cmath>
#include <vector>
#include <assert.h>
#include <limits>
#include <chrono>

/* ******************************************************************************** */

int sieve(int size){
    assert(size>2);

    int i;
    int j;
    
    std::vector<int> vec(size);

    for(vec[1]=0, i=2; i<size; i++)
        vec[i]=1;

    for(i=2; i <= size/2; i++)
        for(j=2; j <= size/i; j++)
            if((i*j)<size)
                vec[i*j] = 0;

    int biggestIdx = 0;

    for(i = 1; i < size; i++)
        if(vec[i])
            biggestIdx = i;

    return biggestIdx;
}

/* ******************************************************************************** */

int sieveUnbounded(){
    unsigned long long i;
    unsigned long long j;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    size_t size = //std::numeric_limits<unsigned long long>::max();
    30000000;

    std::vector<int> vec(pow(10, 9));

    for(vec[1] = 0, i = 2; i < size; i++)
        vec[i] = 1;

    for(i = 2; i <= size / 2; i++)
        for(j = 2; j <= size / i; j++)
            if((i * j) < size)
                vec[i * j] = 0;

    int biggestIdx = 0;

    for(i = 1; i < size; i++)
        if(vec[i])
            biggestIdx = i;

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0 << " seconds";

    return biggestIdx;
}

/* ******************************************************************************** */
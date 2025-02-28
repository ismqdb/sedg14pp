/* ******************************************************************************** */

#include <iostream>
#include <cmath>
#include <vector>
#include <assert.h>
#include <limits>
#include <chrono>

#include "08. sieve.hpp"

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

sieveResult sieveUnbounded(){
    unsigned long long i;
    unsigned long long j;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    size_t size = 30000000;

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

    double d = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0;

    sieveResult result;
    result.idx = biggestIdx;
    result.seconds = d;

    return result;
}

/* ******************************************************************************** */

sieveResult sieveOptimized(){
    unsigned long long i;
    unsigned long long j;

    sieveResult res;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    size_t n = 340000000;

    std::vector<int> lp(n+1);
    std::vector<int> pr;

    for (int i=2; i <= n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }

        for (int j = 0; i * pr[j] <= n; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }

    int biggestIdx = 0;

    for(i = 1; i < n; i++)
        if(lp[i])
            biggestIdx = i;

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    double d = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0;
    res.idx = biggestIdx;
    res.seconds = d;

    return res;
}

/* ******************************************************************************** */
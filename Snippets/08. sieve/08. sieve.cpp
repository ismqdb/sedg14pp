/* ******************************************************************************** */

#include "08. sieve.hpp"

/* ******************************************************************************** */

i32 sieve(i32 size){
    assert(size>2);

    i32 i;
    i32 j;
    
    std::vector<i32> vec(size);

    for(vec[1]=0, i=2; i<size; i++)
        vec[i]=1;

    for(i=2; i <= size/2; i++)
        for(j=2; j <= size/i; j++)
            if((i*j)<size)
                vec[i*j] = 0;

    i32 biggestIdx = 0;

    for(i = 1; i < size; i++)
        if(vec[i])
            biggestIdx = i;

    return biggestIdx;
}

/* ******************************************************************************** */

sieveResult sieveUnbounded(){
    size_t i;
    size_t j;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    size_t size = 30000000;

    std::vector<i32> vec(pow(10, 9));

    for(vec[1] = 0, i = 2; i < size; i++)
        vec[i] = 1;

    for(i = 2; i <= size / 2; i++)
        for(j = 2; j <= size / i; j++)
            if((i * j) < size)
                vec[i * j] = 0;

    i32 biggestIdx = 0;

    for(i = 1; i < size; i++)
        if(vec[i])
            biggestIdx = i;

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    f64 d = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0;

    sieveResult result;
    result.idx = biggestIdx;
    result.seconds = d;

    return result;
}

/* ******************************************************************************** */

sieveResult sieveOptimized(){
    size_t i;
    size_t j;

    sieveResult res;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    size_t n = 340000000;

    std::vector<i32> lp(n+1);
    std::vector<i32> pr;

    for (i32 i=2; i <= n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }

        for (i32 j = 0; i * pr[j] <= n; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }

    i32 biggestIdx = 0;

    for(i = 1; i < n; i++)
        if(lp[i])
            biggestIdx = i;

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    f64 d = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0;
    res.idx = biggestIdx;
    res.seconds = d;

    return res;
}

/* ******************************************************************************** */
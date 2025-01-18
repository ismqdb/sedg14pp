/* ******************************************************************************** */

#include "largestLog.h"

/* ******************************************************************************** */

int largestLogRecursive(int x){
    if(x < 2)
        return 0;
    else
        return largestLogRecursive(x>>1) + 1;
}

/* ******************************************************************************** */

int largestLogIterative(int x){
    int result = 0;

    for(; x > 1; x >>= 1, result++)
        ;

    return result;
}

/* ******************************************************************************** */

void compareLogs(){
    int x = 210556111;
    clock_t t;

    double b1;
    double b2;
    double b3;

    t = clock();
    int a1 = (int)floor(log2(x));
    b1 = ((double)(clock() - t)) / CLOCKS_PER_SEC;

    t = clock();
    int a2 = largestLogRecursive(x);
    b2 = ((double)(clock() - t)) / CLOCKS_PER_SEC;

    t = clock();
    int a3 = largestLogIterative(x);
    b3 = ((double)(clock() - t)) / CLOCKS_PER_SEC;

    printf("%d %0.3f usecs.\n", a1, b1 * 1000000);
    printf("%d %0.3f usecs.\n", a2, b2 * 1000000);
    printf("%d %0.3f usecs.\n", a3, b3 * 1000000);
}

/* ******************************************************************************** */
/* ******************************************************************************** */

#include "./01. gcd.h"

/* ******************************************************************************** */

void swap(unsigned long long *x, unsigned long long *y){
    unsigned long long z;

    z = *x;
    *x = *y;
    *y = z;
}

/* ******************************************************************************** */

unsigned long long gcd(unsigned long long u, unsigned long long v){
    unsigned long long t;

    u = abs(u);
    v = abs(v);

    while(u > 0){
        if(u < v)
            swap(&u, &v);
        u = u-v;
    }
    return v;
}

/* ******************************************************************************** */

unsigned long long gcdRecursive(unsigned long long *u, unsigned long long *v){
    unsigned long long t;

    *u = abs(*u);
    *v = abs(*v);

    if(*u > 0){
        if(*u < *v)
            swap(u, v);
        *u %= *v;
        gcdRecursive(u, v);
    }
    return *v;
}

/* ******************************************************************************** */

unsigned long long gcdMod(unsigned long long u, unsigned long long v){
    unsigned long long t;

    //u = abs(u);
    //v = abs(v);

    while(u>0){
        if(u<v)
            swap(&u, &v);
        printf("%lu %lu\n", u, v);
        u %= v;
    }
    printf("%lu %lu\n", u, v);
    return v;
}

/* ******************************************************************************** */

unsigned long long gcd3(unsigned long long x, unsigned long long y, unsigned long long z){
    return gcdMod(gcdMod(x,y), z);
}

/* ******************************************************************************** */
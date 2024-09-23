#include "./01. gcd.h"

void swap(unsigned long long *x, unsigned long long *y){
    unsigned long long z;

    z = *x;
    *x = *y;
    *y = z;
}

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

unsigned long long gcd_mod(unsigned long long u, unsigned long long v){
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

unsigned long long gcd_3(unsigned long long x, unsigned long long y, unsigned long long z){
    return gcd_mod(gcd_mod(x,y), z);
}

void main_gcd(){
    unsigned long long x, y;
    while(scanf("%d %d", &x, &y) != EOF)
        if(x>0 && y>0)
            printf("%d %d %d\n", x, y, gcd(x,y));
}
#include <stdio.h>
#include <stdlib.h>

void swap(size_t *x, size_t *y){
    size_t z;

    z = *x;
    *x = *y;
    *y = z;
}

size_t gcd(size_t u, size_t v){
    size_t t;

    u = abs(u);
    v = abs(v);

    while(u > 0){
        if(u < v)
            swap(&u, &v);
        u = u-v;
    }
    return v;
}

size_t gcd_mod(size_t u, size_t v){
    size_t t;

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

size_t gcd_3(size_t x, size_t y, size_t z){
    return gcd_mod(gcd_mod(x,y), z);
}

void driver_gcd(){
    size_t x, y;
    while(scanf("%d %d", &x, &y) != EOF)
        if(x>0 && y>0)
            printf("%d %d %d\n", x, y, gcd(x,y));
}
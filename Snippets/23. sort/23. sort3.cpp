/* ******************************************************************************** */

#include "./23. sort3.hpp"

/* ******************************************************************************** */

#define maxn 100

/* ******************************************************************************** */

void sort3(i32 a[], i32 n){
    assert(n == 3);

    i32 t;

    if(a[1] > a[2]){
        t = a[1];
        a[1] = a[2];
        a[2] = t;
    }

    if(a[1] > a[3]){
        t = a[1];
        a[1] = a[3];
        a[3] = t;
    }

    if(a[2] > a[3]){
        t = a[2];
        a[2] = a[3];
        a[3] = t;
    }
}

/* ******************************************************************************** */

void s3driver(){
    i32 n;
    i32 i;
    i32 a[maxn];

    n = 0;
    assert(n <= maxn);

    while(std::cin >> a[n+1])
        n++;

    a[0] = 0;
    sort3(a, n);

    for(i = 0; i <= n; i++){
        if(i < n)
            assert(a[i] < a[i+1]);
        std::cout << a[i] << ' ';
    }

    std::cout << '\n';
}

/* ******************************************************************************** */
#include "./23. sort3.hpp"

#define maxn 100

none sort4(i32 a[], i32 n){
    assert(n == 4);

    i32 t;

    if(a[0] > a[1]){
        t = a[0];
        a[0] = a[1];
        a[1] = t;
    }

    if(a[0] > a[2]){
        t = a[0];
        a[0] = a[2];
        a[2] = t;
    }

    if(a[0] > a[3]){
        t = a[0];
        a[0] = a[3];
        a[3] = t;
    }

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
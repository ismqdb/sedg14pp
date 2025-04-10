/* ******************************************************************************** */

#include "./23. sort.hpp"

/* ******************************************************************************** */

void selectionSort(i32 a[], i32 n){
    i32 min;
    i32 temp;

    for(i32 i = 0; i < n; i++){
        min = i;

        for(i32 k = i; k < n; k++)
            if(a[k] < a[min])
                min = k;

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

/* ******************************************************************************** */

void insertionSort(i32 a[], i32 n){
    for(i32 i = 1; i <= n; i++){
        i32 k = i;
        i32 temp = a[k];

        while(temp < a[k-1]){
            a[k] = a[k-1];
            k--;
        }
        a[k] = temp;
    }
}

/* ******************************************************************************** */

void bubbleSort(i32 a[], i32 n){
    i32 t;

    for(i32 i = n; i >= 1; i--)
        for(i32 j = 0; j <= i; j++)
            if(a[j-1] > a[j]){
                t = a[j-1];
                a[j-1] = a[j];
                a[j] = t;
            }
}

/* ******************************************************************************** */

void insertionSortLargeRecord(i32 a[], i32 p[], i32 n){
    i32 v;
    i32 j;

    for(i32 i = 0; i <= n; i++)
        p[i] = i;

    for(i32 i = 2; i <= n; i++){
        v = p[i];
        j = i;

        while(a[p[j-1]] > a[v]){
            p[j] = p[j-1];
            j--;
        }
        p[j] = v;
    }
}

/* ******************************************************************************** */
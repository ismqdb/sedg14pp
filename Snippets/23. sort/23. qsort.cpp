/* ******************************************************************************** */

#include "23. qsort.hpp"

/* ******************************************************************************** */

none qsort(i32 array[], i32 left, i32 right){
    i32 i;
    i32 v;
    i32 j;
    i32 t;

    if(right > left){
        v = array[right];
        i = left-1;
        j = right;

        while(1){
            while(array[++i] < v)
                ;
            
            while(array[--j] > v)
                ;

            if(i>=j) break;

            t = array[i];
            array[i] = array[j];
            array[j] = t;
        }

        t = array[i];
        array[i] = array[right];
        array[right] = t;

        qsort(array, left, i-1);
        qsort(array, i+1, right);
    }
}

/* ******************************************************************************** */
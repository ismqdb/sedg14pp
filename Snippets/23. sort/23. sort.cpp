/* ******************************************************************************** */

#include "./23. sort.hpp"

/* ******************************************************************************** */

none bubbleSort(i32 array[], i32 size){
    i32 temp;

    for(i32 i = size; i >= 1; i--)
        for(i32 j = 0; j <= i; j++)
            if(array[j-1] > array[j]){
                temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
            }
}

/* ******************************************************************************** */

none selectionSort(i32 array[], i32 size){
    i32 min;
    i32 temp;

    for(i32 i = 0; i < size; i++){
        min = i;

        for(i32 k = i; k < size; k++)
            if(array[k] < array[min])
                min = k;

        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

/* ******************************************************************************** */

none shellSort(i8 array[], i32 size, i32 h){
    i32 i;
    i32 j;
    i32 temp;

    if(h <= 0)
        for(h = 1; h <= size/9; h = 3*h+1)
            ;

    while(h = hreduce(h)){
        for(i = h; i < size; i++){
            temp = array[i];
            j = i;

            while(j>=h && array[j-h]>temp){
                array[j] = array[j-h];
                j -= h;
            }
            array[j] = temp;
        }
    }
}

/* ******************************************************************************** */

i32 hreduce(i32 in) {
    i32 coef = 3;

    if (in > 1 && (in / coef) == 0)
        return 1;
    else
        return in / coef;
}

/* ******************************************************************************** */
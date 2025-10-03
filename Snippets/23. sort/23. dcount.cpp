/* ******************************************************************************** */

#include "23. dcount.hpp"

/* ******************************************************************************** */

none simpledc(i32 size){
    i32 array[size];
    i32 idx[size];

    for(i32 i = 0; i < size; i++){
        array[i] = i;
        idx[i] = (size-1)-i;
    }

    for(i32 i = 0; i < size-1; i++)
        idx[array[i]] = array[i];

    for(i32 i = 0; i < size-1; i++)
        std::cout << array[idx[i]] << ' ';
}

/* ******************************************************************************** */

// N records
// keys: [0, M-1]

none distrCount(i32 *in, i32 noOfElems, i32 maxKey){
    i32 count[maxKey];
    i32 out[noOfElems];

    memset(count, 0, maxKey*sizeof(i32));
    memset(out, 0, noOfElems*sizeof(i32));

    for(i32 i = 0; i < noOfElems; i++)
        count[in[i]]++;

    for(i32 i = N-1; i > 0; i--){
        b[count[a[i]]] = a[i];
        count[a[i]]--;
    }
    
    for(i32 i = 1; i <= N; i++)
        a[i] = b[i];

    for(i32 i = 0; i < M; i++)
        std::cout << count[i] << ' ';
        
    putchar(10);
}

/* ******************************************************************************** */
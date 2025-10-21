/* ******************************************************************************** */

#include "23. dcount.hpp"

/* ******************************************************************************** */

none simpledc(i32 size){
    std::vector<i32> array{ size };
    std::vector<i32> idx{ size };

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

// noOfElems records
// keys: [0, maxKey-1]

none distrCount(i32 *in, i32 noOfElems, i32 maxKey){
    std::vector<i32> count{ maxKey };
    std::vector<i32> out{ noOfElems };

    for(i32 i = 0; i < noOfElems; i++)
        count[in[i]]++;

    for(i32 j = 0; j < maxKey; j++)
        count[j] = count[j-1] + count[j];

    for(i32 i = noOfElems-1; i > -1; i--){
        out[count[in[i]]-1] = in[i];
        count[in[i]]--;
    }
    
    for(i32 i = 0; i < noOfElems; i++)
        in[i] = out[i];
}

/* ******************************************************************************** */

// noOfElems records
// keys: n, m

none distrCountBinary(i32 *in, i32 noOfElems) {
    std::vector<i32> count(2);
    std::vector<i32> out(noOfElems);

    i32 x = in[0];
    i32 y = in[0];

    for (i32 i = 0; i < noOfElems; i++) {
        if (in[i] != x && in[i] != y)
            y = in[i];
        if (in[i] == in[0])
            count[0]++;
        else
            count[1]++;
    }

    i32 counter = 0;

    for (i32 i = 0; i < count[0]; i++, counter++)
        out[counter] = x;

    for (i32 i = 0; i < count[1]; i++, counter++)
        out[counter] = y;

    for (i32 i = 0; i < noOfElems; i++)
        in[i] = out[i];
}

/* ******************************************************************************** */
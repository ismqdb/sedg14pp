/* ******************************************************************************** */

#include <iostream>
#include <cmath>
#include <vector>

/* ******************************************************************************** */

void sieve(int size){
    if(size < 2){
        fprintf(stderr, "Sieve: less than 2 elements.\n");
        return;
    }

    int i,j;
    
    std::vector<int> vec(size);

    for(vec[1]=0, i=2; i<size; i++)
        vec[i]=1;

    for(i=2; i <= size/2; i++)
        for(j=2; j <= size/i; j++)
            if((i*j)<size)
                vec[i*j] = 0;

    for(i = 1; i < size; i++)
        if(vec[i])
            std::cout << i << ' ';

    putchar(10);
}

/* ******************************************************************************** */
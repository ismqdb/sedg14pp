#include "./14. 2DArray.hpp"

i32 calculate2dArray(){
    std::vector<std::vector<i32>> array;

    for(i32 i = 1; i < array.size(); i++)
        for(i32 j = 1; j < array[i].size(); j++)
            if(gcd(i, j) == 1)
                array[i][j] = 1;
            else
                array[i][j] = 0;

    putchar(10); 

    return 1;
}
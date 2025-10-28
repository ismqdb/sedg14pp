/* ******************************************************************************** */

#include "23. shellSort.hpp"

/* ******************************************************************************** */

i32 shellSortTimed(i32 array[], i32 size, std::vector<i32>(*func)(i32)) 
{
    i32 i;
    i32 j;
    i32 temp;

    std::vector<i32> sequence = func(size);

    auto start = std::chrono::steady_clock::now(); 
    
    for
    (
        i32 seq_iter = sequence.size()-1, h = sequence[seq_iter]; 
        seq_iter > -1; 
        seq_iter--
    ) 
    {
        h = sequence[seq_iter];
        for (i = h; i < size; i++) 
        {
            temp = array[i];
            j = i;

            while (j >= h && array[j - h] > temp) 
            {
                array[j] = array[j - h];
                j -= h;
            }
            array[j] = temp;
        }
    }

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    return std::chrono::duration<double, std::micro>(diff).count();
}

/* ******************************************************************************** */

none shellSort(i8 array[], i32 size)
{
    i32 i;
    i32 j;
    i32 h;
    i32 temp;

    for(h = 1; h <= size/9; h = 3*h+1)
        ;

    for(; h > 0; h /= 3){
        for(i = h; i < size; i++)
        {
            temp = array[i];
            j = i;

            while(j>=h && array[j-h]>temp)
            {
                array[j] = array[j-h];
                j -= h;
            }
            array[j] = temp;
        }
    }
}

/* ******************************************************************************** */

std::vector<i32> shell_seq(i32 size) 
{
    std::vector<i32> vec;
    i32 h;

    for (h = 1; h <= size / 9; h = 3 * h + 1)
        vec.push_back(h);

    return vec;
}

/* ******************************************************************************** */

std::vector<i32> knuth_seq(i32 size) 
{
    std::vector<i32> vec;
    i32 h = 1;

    for (i32 i = 0; h <= size / 9; i++) 
    {
        vec.push_back(h);
        h = pow(3, i) / 2;
    }

    return vec;
}

/* ******************************************************************************** */

std::vector<i32> hibbard_seq(i32 size) 
{
    std::vector<i32> vec;
    i32 h = 1;

    for (i32 i = 0; h <= size / 9; i++) 
    {
        vec.push_back(h);
        h = pow(2, i) - 1;
    }

    return vec;
}

/* ******************************************************************************** */

std::vector<i32> sedg_seq_1(i32 size) 
{
    std::vector<i32> vec;
    i32 h = 1;

    for (i32 i = 0; h <= size / 9; i++) 
    {
        vec.push_back(h);
        h = 9 * pow(2, i) - 9 * pow(2, i / 2) + 1;
    }

    return vec;
}

/* ******************************************************************************** */

std::vector<i32> sedg_seq_2(i32 size) 
{
    std::vector<i32> vec;
    i32 h = 1;

    for (i32 i = 0; h <= size / 9; i++) 
    {
        vec.push_back(h);
        h = pow(4, i) - 3 * pow(2, i) + 1;
    }

    return vec;
}

/* ******************************************************************************** */

std::vector<i32> tokuda_seq(i32 size) 
{
    std::vector<i32> vec;
    i32 h = 1;

    for (i32 i = 0; h <= size / 9; i++) 
    {
        vec.push_back(h);
        h = ceil(2.25 * h);
    }

    return vec;
}

/* ******************************************************************************** */
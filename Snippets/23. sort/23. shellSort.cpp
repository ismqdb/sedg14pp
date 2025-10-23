/* ******************************************************************************** */

#include "23. shellSort.hpp"

/* ******************************************************************************** */

none shellSort(i8 array[], i32 size) {
    i32 i;
    i32 j;
    i32 temp;

    i32 h = shell_inc(size);

    while (h = shell_dec(h)) {
        for (i = h; i < size; i++) {
            temp = array[i];
            j = i;

            while (j >= h && array[j - h] > temp) {
                array[j] = array[j - h];
                j -= h;
            }
            array[j] = temp;
        }
    }
}

/* ******************************************************************************** */

std::vector<i32> shell_seq(i32 size) {
    std::vector<i32> vec;
    i32 h;

    for (h = 1; h <= size / 9; h = 3 * h + 1)
        vec.push_back(h);

    return vec;
}

/* ******************************************************************************** */

std::vector<i32> knuth_seq(i32 size) {
    std::vector<i32> vec;
    i32 h = 1;

    for (i32 i = 0; h <= size / 9; i++) {
        vec.push_back(h);
        h = pow(3, i) / 2;
    }

    return vec;
}

/* ******************************************************************************** */

std::vector<i32> hibbard_seq(i32 size) {
    std::vector<i32> vec;
    i32 h = 1;

    for (i32 i = 0; h <= size / 9; i++) {
        vec.push_back(h);
        h = pow(2, i) - 1;
    }

    return vec;
}

/* ******************************************************************************** */

std::vector<i32> sedg_seq_1(i32 size) {
    std::vector<i32> vec;
    i32 h = 1;

    for (i32 i = 0; h <= size / 9; i++) {
        vec.push_back(h);
        h = 9 * pow(2, i) - 9 * pow(2, i / 2) + 1;
    }

    return vec;
}

/* ******************************************************************************** */

std::vector<i32> sedg_seq_2(i32 size) {
    std::vector<i32> vec;
    i32 h = 1;

    for (i32 i = 0; h <= size / 9; i++) {
        vec.push_back(h);
        h = pow(4, i) - 3 * pow(2, i) + 1;
    }

    return vec;
}

/* ******************************************************************************** */

std::vector<i32> tokuda_seq(i32 size) {
    std::vector<i32> vec;
    i32 h = 1;

    for (i32 i = 0; h <= size / 9; i++) {
        vec.push_back(h);
        h = ceil(2.25 * h);
    }

    return vec;
}

/* ******************************************************************************** */
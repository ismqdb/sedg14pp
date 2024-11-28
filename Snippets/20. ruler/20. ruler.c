/* ******************************************************************************** */

#include "./20. ruler.h"

/* ******************************************************************************** */

void mark(int position, int size){}

/* ******************************************************************************** */

int ruler_mark_height(int num){
    if(num < 1)
        return 1;

    int count = 0;

    while((num & 1) == 0){
        count++;
        num >>= 1;
    }

    return count;
}

/* ******************************************************************************** */

void rule_level_order(int left, int right, int tree_height){
    for(int i = 1, j = 1; i <= tree_height; i++, j <<= 1)
        for(int t = 0; t <= (left + right)/j; t++)
            mark(left + j + t * (j+j), i);
}

/* ******************************************************************************** */

void rule_pre_order(int left, int right, int height){
    int middle = (left+right)/2;

    if(height > 0){
        mark(middle, height);
        rule_pre_order(left, middle, height-1);
        rule_pre_order(middle, right, height-1);
    }
}

/* ******************************************************************************** */

void rule_in_order(int left, int right, int height){
    int middle = (left+right)/2;

    if(height > 0){
        rule_in_order(left, middle, height-1);
        mark(middle, height);
        rule_in_order(middle, right, height-1);
    }
}

/* ******************************************************************************** */

void rule_iterative(int left, int right, int height){
    for(int i = 1; i <= (right-left); i++)
        mark(i, ruler_mark_height(i));
}

/* ******************************************************************************** */
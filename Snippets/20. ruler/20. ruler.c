/* ******************************************************************************** */

#include "./20. ruler.h"

/* ******************************************************************************** */

void mark(int position, int size){}

/* ******************************************************************************** */

int rulerMarkHeight(int num){
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

void ruleLevelOrder(int left, int right, int tree_height){
    for(int i = 1, j = 1; i <= tree_height; i++, j <<= 1)
        for(int t = 0; t <= (left + right)/j; t++)
            mark(left + j + t * (j+j), i);
}

/* ******************************************************************************** */

void rulePreOrder(int left, int right, int height){
    int middle = (left+right)/2;

    if(height > 0){
        mark(middle, height);
        rulePreOrder(left, middle, height-1);
        rulePreOrder(middle, right, height-1);
    }
}

/* ******************************************************************************** */

void ruleInOrder(int left, int right, int height){
    int middle = (left+right)/2;

    if(height > 0){
        ruleInOrder(left, middle, height-1);
        mark(middle, height);
        ruleInOrder(middle, right, height-1);
    }
}

/* ******************************************************************************** */

void ruleIterative(int left, int right, int height){
    for(int i = 1; i <= (right-left); i++)
        mark(i, rulerMarkHeight(i));
}

/* ******************************************************************************** */
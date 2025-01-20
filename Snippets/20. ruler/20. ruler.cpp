/* ******************************************************************************** */

#include "./20. ruler.hpp"

/* ******************************************************************************** */

void mark(int position, int size){
    std::cout << position << ", " << size << " | "; 
}

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
        std::cout << std::endl;
}

/* ******************************************************************************** */

void rulePreorder(int left, int right, int height){
    int middle = (left+right)/2;

    if(height > 0){
        mark(middle, height);
        rulePreorder(left, middle, height-1);
        rulePreorder(middle, right, height-1);
    }
}

/* ******************************************************************************** */

void ruleInorder(int left, int right, int height){
    int middle = (left+right)/2;

    if(height > 0){
        ruleInorder(left, middle, height-1);
        mark(middle, height);
        ruleInorder(middle, right, height-1);
    }
}

/* ******************************************************************************** */

void ruleIterative(int left, int right, int height){
    for(int i = 1; i < (right-left); i++)
        mark(i, rulerMarkHeight(i));
}

/* ******************************************************************************** */
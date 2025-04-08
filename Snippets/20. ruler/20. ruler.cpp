/* ******************************************************************************** */

#include "./20. ruler.hpp"

/* ******************************************************************************** */

void mark(i32 position, i32 size){
    std::cout << position << ", " << size << " | "; 
}

/* ******************************************************************************** */

i32 rulerMarkHeight(i32 num){
    if(num < 1)
        return 1;

    i32 count = 0;

    while((num & 1) == 0){
        count++;
        num >>= 1;
    }

    return count;
}

/* ******************************************************************************** */

void ruleLevelOrder(i32 left, i32 right, i32 treeHeight){
    for(i32 i = 1, j = 1; i <= treeHeight; i++, j <<= 1)
        for(i32 t = 0; t <= (left + right)/j; t++)
            mark(left + j + t * (j+j), i);
        std::cout << std::endl;
}

/* ******************************************************************************** */

void rulePreorder(i32 left, i32 right, i32 height){
    i32 middle = (left+right)/2;

    if(height > 0){
        mark(middle, height);
        rulePreorder(left, middle, height-1);
        rulePreorder(middle, right, height-1);
    }
}

/* ******************************************************************************** */

void ruleInorder(i32 left, i32 right, i32 height){
    i32 middle = (left+right)/2;

    if(height > 0){
        ruleInorder(left, middle, height-1);
        mark(middle, height);
        ruleInorder(middle, right, height-1);
    }
}

/* ******************************************************************************** */

void ruleIterative(i32 left, i32 right, i32 height){
    for(i32 i = 1; i < (right-left); i++)
        mark(i, rulerMarkHeight(i));
}

/* ******************************************************************************** */
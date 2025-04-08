/* ******************************************************************************** */

#include <iostream>
#include <future>
#include <thread>
#include <cmath>

/* ******************************************************************************** */

#include "Snippets/00. includes/rand/rand.hpp"
#include "Snippets/23. sort/23. sort.hpp"

/* ******************************************************************************** */

int main(){
    std::vector<i32> vec = getRandVec(10, 0, 50);
    selectionSort(vec.data(), vec.size());

   vec = getRandVec(10, 0, 50);
   insertionSort(vec.data(), vec.size()); 

   vec = getRandVec(10, 0, 50);
   bubbleSort(vec.data(), vec.size()); 
}

/* ******************************************************************************** */
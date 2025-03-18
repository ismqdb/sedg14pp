/* ******************************************************************************** */

#include <iostream>
#include <future>
#include <thread>
#include <cmath>

#include "Snippets/23. sort/23. sort3.hpp"

#include "Snippets/00. includes/result/result.hpp"

/* ******************************************************************************** */

result<int> increment(int x){
    return result<int>::success(x+1);
}

int main(){
    int a[] = {1, 5, 7, 6, 3};
    selectionSort(a, 5);

    std::cout << increment(5).value() << '\n';
}

/* ******************************************************************************** */
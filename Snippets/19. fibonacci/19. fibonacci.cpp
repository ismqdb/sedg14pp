/* ******************************************************************************** */

#include "./19. fibonacci.hpp"

/* ******************************************************************************** */

int fibonacciRecursive(int n){
    if(n < 0)
        return -1;

    if(n <= 1)
        return 1;
    
    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}

/* ******************************************************************************** */

int fibonacciIterative(int n){
    int i;
    int array[n+2];
    array[0] = array[1] = 1;

    for(i = 2; i <= n; i++)
        array[i] = array[i-1] + array[i-2];
        
    return array[n];
}

/* ******************************************************************************** */
#include "./19. fibonacci.h"

int fibonacci_recursive(int n){
    if(n <= 1)
        return 1;
    
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

int fibonacci_iterative(int n){
    int i;
    int array[n];
    array[0] = array[1] = 1;

    for(i = 2; i <= n; i++)
        array[i] = array[i-1] + array[n-2];
        
    return array[n];
}
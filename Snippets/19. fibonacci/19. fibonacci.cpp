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

int fibonacciRR1(int n){
    if(n < 0)
        return -1;

    if(n <= 1)
        return 1;
    
    std::stack<int> stack;

    for(int i = n; i >= 2; i--)
        stack.push(i);

    stack.push(1);

    while(stack.size() > 1){
        int n1 = stack.top();
        stack.pop();

        int n2 = stack.top();
        stack.pop();

        stack.push(n1+n2);
    }  

    return stack.top();  
}

/* ******************************************************************************** */

int fibonacciRR2(int n){
    if(n < 0)
        return -1;

    if(n <= 1)
        return 1;
    
    std::stack<int> stack;
    int array[n+2];

    for(int i = n; i >= 2; i--)
        stack.push(i);

    stack.push(1);

    array[0] = array[1] = 1;

    for(int i = 2; !stack.empty(); i++){
        int n1 = stack.top();
        stack.pop();

        array[i] = n1+array[i-1];
    }  

    return array[n]; 
}

/* ******************************************************************************** */
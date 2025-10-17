/* ******************************************************************************** */

#include "./19. fibonacci.hpp"

/* ******************************************************************************** */

i32 fibonacciRecursive(i32 n){
    if(n < 0)
        return -1;

    if(n <= 1)
        return 1;
    
    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}

/* ******************************************************************************** */

i32 fibonacciIterative(i32 n){
    i32 i;
    std::vector<i32> array{ n+2 };
    array[0] = array[1] = 1;

    for(i = 2; i <= n; i++)
        array[i] = array[i-1] + array[i-2];
        
    return array[n];
}

/* ******************************************************************************** */

i32 fibonacciRR1(i32 n){
    if(n < 0)
        return -1;

    if(n <= 1)
        return 1;
    
    std::stack<i32> stack;

    for(i32 i = n; i >= 2; i--)
        stack.push(i);

    stack.push(1);

    while(stack.size() > 1){
        i32 n1 = stack.top();
        stack.pop();

        i32 n2 = stack.top();
        stack.pop();

        stack.push(n1+n2);
    }  

    return stack.top();  
}

/* ******************************************************************************** */

i32 fibonacciRR2(i32 n){
    if(n < 0)
        return -1;

    if(n <= 1)
        return 1;
    
    std::stack<i32> stack;
    
    std::vector<i32> array{ n };

    for(i32 i = n; i >= 2; i--)
        stack.push(i);

    stack.push(1);

    array[0] = array[1] = 1;

    for(i32 i = 2; !stack.empty(); i++){
        i32 n1 = stack.top();
        stack.pop();

        array[i] = n1+array[i-1];
    }  

    return array[n]; 
}

/* ******************************************************************************** */
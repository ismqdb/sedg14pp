/* ******************************************************************************** */

#include "./19. fibonacci.h"

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

int fibonacciRecursive(int n){
    if(n < 0)
        return -1;

    if(n <= 1)
        return 1;
    
    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}

/* ******************************************************************************** */

int fibonacciRR1(int n){
    if(n < 0)
        return -1;

    if(n <= 1)
        return 1;
    
    struct stackArray stack = stackArrayInit(INT, 50);

    for(int i = n; i >= 2; i--)
        stackArrayPushInt(&stack, i);

    stackArrayPushInt(&stack, 1);

    while(stackArraySize(&stack) > 1){
        int n1 = stackArrayPopInt(&stack);
        int n2 = stackArrayPopInt(&stack);

        stackArrayPushInt(&stack, n1+n2);
    }  

    return stackArrayPopInt(&stack);
}

/* ******************************************************************************** */

int fibonacciRR2(int n){
    if(n < 0)
        return -1;

    if(n <= 1)
        return 1;
    
    struct stackArray stack = stackArrayInit(INT, 50);
    int array[n+2];

    for(int i = n; i >= 2; i--)
        stackArrayPushInt(&stack, i);

    stackArrayPushInt(&stack, 1);

    array[0] = 1;

    for(int i = 2; !stackArrayIsEmpty(&stack); i++){
        int n1 = stackArrayPopInt(&stack);

        array[i] = n1+array[i-1];
    }  

    return array[n]; 
}

/* ******************************************************************************** */

int fibonacciRR3(){
    
}

/* ******************************************************************************** */
/* ******************************************************************************** */

#include "./19. fibonacci.h"

/* ******************************************************************************** */

int fibonacci_recursive(int n){
    if(n < 0)
        return -1;

    if(n <= 1)
        return 1;
    
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

/* ******************************************************************************** */

int fibonacci_iterative(int n){
    int i;
    int array[n+2];
    array[0] = array[1] = 1;

    for(i = 2; i <= n; i++)
        array[i] = array[i-1] + array[i-2];
        
    return array[n];
}

/* ******************************************************************************** */

int fibonacci_rr1(int n){
    if(n < 0)
        return -1;

    if(n <= 1)
        return 1;
    
    stackArray stack = stackArrayInit(INT, 50);

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

int fibonacci_rr2(int n){
    if(n < 0)
        return -1;

    if(n <= 1)
        return 1;
    
    stackArray stack = stackArrayInit(INT, 50);
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
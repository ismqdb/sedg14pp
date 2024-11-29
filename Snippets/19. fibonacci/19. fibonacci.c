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
    
    stack_a stack = stack_a_init(integer, 50);

    for(int i = n; i >= 2; i--)
        stack_a_push_int(&stack, i);

    stack_a_push_int(&stack, 1);

    while(stack_a_size(&stack) > 1){
        int n1 = stack_a_pop_int(&stack);
        int n2 = stack_a_pop_int(&stack);

        stack_a_push_int(&stack, n1+n2);
    }  

    return stack_a_pop_int(&stack);
}

/* ******************************************************************************** */

int fibonacci_rr2(int n){
    if(n < 0)
        return -1;

    if(n <= 1)
        return 1;
    
    stack_a stack = stack_a_init(integer, 50);
    int array[n+2];

    for(int i = n; i >= 2; i--)
        stack_a_push_int(&stack, i);

    stack_a_push_int(&stack, 1);

    array[0] = 1;

    for(int i = 2; !stack_a_is_empty(&stack); i++){
        int n1 = stack_a_pop_int(&stack);

        array[i] = n1+array[i-1];
    }  

    return array[n]; 
}

/* ******************************************************************************** */
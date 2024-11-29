/* ******************************************************************************** */

#include "./postfix.h"

/* ******************************************************************************** */

array getPostfix(){
    char c;
    stack_ll stack_ll = stack_ll_init();

    array array = createArray(INT);

    while(1){
        int readResult = scanf("%1c", &c);
        if(readResult == EOF || c == '\n')
            break;

        if(c == ')'){
            insertInt(&array, (char)stack_ll_pop_int(stack_ll));
        }

        if(c == '+')
            stack_ll_push_int(stack_ll, (int)c);

        if(c == '*')
            stack_ll_push_int(stack_ll, (int)c);

        while(c >= '0' && c <= '9'){
            insertInt(&array, c);
            scanf("%1c", &c);
        }

        if(c != '(')
            insertInt(&array, ' ');
            
    }

    while(!stack_ll_is_empty(stack_ll))
        insertInt(&array, (char)stack_ll_pop_int(stack_ll));

    //printf("\n");
    return array;
}

/* ******************************************************************************** */

int evaluate(array *array){
    char c;
    int x;
    int sum = 0;

    stack_ll stack_ll = stack_ll_init();
    for(int i = 0; i < array->currentSize; i++){
        c = array->data.ints[i];

        if(c == ' ')
            continue;

        x = 0;

        if(c == '+')
            x = stack_ll_pop_int(stack_ll) + stack_ll_pop_int(stack_ll); 

        if(c == '*')
            x = stack_ll_pop_int(stack_ll) * stack_ll_pop_int(stack_ll);

        while(c>='0' && c<='9'){
            x = 10*x + (c-'0');
            i++;
            c = array->data.ints[i];
        }
        stack_ll_push_int(stack_ll, x);
    }

    return x;
}

/* ******************************************************************************** */
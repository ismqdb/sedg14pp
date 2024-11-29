/* ******************************************************************************** */

#include "./postfix.h"

/* ******************************************************************************** */

struct array getPostfix(){
    char c;
    struct stackLL stack = stackLLInit();

    struct array array = createArray(INT);

    while(1){
        int readResult = scanf("%1c", &c);
        if(readResult == EOF || c == '\n')
            break;

        if(c == ')'){
            insertInt(&array, (char)stackLLPopInt(&stack));
        }

        if(c == '+')
            stackLLPushInt(&stack, (int)c);

        if(c == '*')
            stackLLPushInt(&stack, (int)c);

        while(c >= '0' && c <= '9'){
            insertInt(&array, c);
            scanf("%1c", &c);
        }

        if(c != '(')
            insertInt(&array, ' ');
            
    }

    while(!stackLLIsEmpty(&stack))
        insertInt(&array, (char)stackLLPopInt(&stack));

    //printf("\n");
    return array;
}

/* ******************************************************************************** */

int evaluate(struct array *array){
    char c;
    int x;
    int sum = 0;

    struct stackLL stack = stackLLInit();
    for(int i = 0; i < array->currentSize; i++){
        c = array->data.ints[i];

        if(c == ' ')
            continue;

        x = 0;

        if(c == '+')
            x = stackLLPopInt(&stack) + stackLLPopInt(&stack); 

        if(c == '*')
            x = stackLLPopInt(&stack) * stackLLPopInt(&stack);

        while(c>='0' && c<='9'){
            x = 10*x + (c-'0');
            i++;
            c = array->data.ints[i];
        }
        stackLLPushInt(&stack, x);
    }

    return x;
}

/* ******************************************************************************** */
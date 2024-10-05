#include "./11a. postfix.h"

array_char get_postfix(){
    char c;
    stack_ll stack_ll = stack_ll_init();

    array_char array = create_array_char(25);

    while(1){
        int readResult = scanf("%1c", &c);
        if(readResult == EOF || c == '\n')
            break;

        if(c == ')'){
            insert_array_char(&array, (char)stack_ll_pop_int(stack_ll));
        }

        if(c == '+')
            stack_ll_push_int(stack_ll, (int)c);

        if(c == '*')
            stack_ll_push_int(stack_ll, (int)c);

        while(c >= '0' && c <= '9'){
            insert_array_char(&array, c);
            scanf("%1c", &c);
        }

        if(c != '(')
            insert_array_char(&array, ' ');
            
    }

    while(!stack_ll_is_empty(stack_ll))
        insert_array_char(&array, (char)stack_ll_pop_int(stack_ll));

    return array;
}

int evaluate(array_char *array){
    char c;
    int x;
    int sum = 0;

    stack_ll stack_ll = stack_ll_init();
    for(int i = 0; i < array->current_size; i++){
        c = array->data[i];

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
            c = array->data[i];
        }
        stack_ll_push_int(stack_ll, x);
    }

    return x;
}
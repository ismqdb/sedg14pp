#include "./11. stack_ll.c"

struct array get_postfix(){
    char c;
    stack_ll stack_ll = stack_init();

    struct array array = createArray();

    while(1){
        int readResult = scanf("%1c", &c);
        if(readResult == EOF || c == '\n')
            break;

        if(c == ')'){
            insert(&array, (char)pop(stack_ll));
        }

        if(c == '+')
            push(stack_ll, (int)c);

        if(c == '*')
            push(stack_ll, (int)c);

        while(c >= '0' && c <= '9'){
            insert(&array, c);
            scanf("%1c", &c);
        }

        if(c != '(')
            insert(&array, ' ');
            
    }

    while(!is_empty(stack_ll))
        //printf("%1c", (char)pop());
        insert(&array, (char)pop(stack_ll));

    //printf("\n");
    return array;
}

int evaluate(struct array *array){
    char c;
    int x;
    int sum = 0;

    stack_ll stack_ll = stack_init();
    for(int i = 0; i < array->currentSize; i++){
        c = array->start[i];

        if(c == ' ')
            continue;

        x = 0;

        if(c == '+')
            x = pop(stack_ll) + pop(stack_ll); 

        if(c == '*')
            x = pop(stack_ll) * pop(stack_ll);

        while(c>='0' && c<='9'){
            x = 10*x + (c-'0');
            i++;
            c = array->start[i];
        }
        push(stack_ll, x);
    }

    return x;
}
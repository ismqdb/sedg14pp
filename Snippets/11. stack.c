#include <stdio.h>
#include <ctype.h>

#ifndef INCLUDE_ARRAY_C
#define INCLUDE_ARRAY_C
    #include "../array.c"
#endif

static struct node {
    int key;
    struct node *next;
};

static struct node *head, *z;

struct node *n_alloc(){
    return (struct node*)malloc(sizeof(*head));
}

void stack_init(){
    head = n_alloc();
    z = n_alloc();

    head->next = z;
    head->key = 0;
    z->next = z;
}

void push(int v){
    struct node *t = n_alloc();
    t->key = v;
    t->next = head->next;
    head->next = t; 
}

int pop(){
    int x;
    struct node *t = head->next;
    head->next = t->next;
    x = t->key;
    free(t);
    return x;
}

int is_empty(){
    return head->next == z;
}

struct array get_postfix(){
    char c;
    stack_init();

    struct array array = createArray();

    while(1){
        int readResult = scanf("%1c", &c);
        if(readResult == EOF || c == '\n')
            break;

        if(c == ')'){
            insert(&array, (char)pop());
        }

        if(c == '+')
            push((int)c);

        if(c == '*')
            push((int)c);

        while(c >= '0' && c <= '9'){
            insert(&array, c);
            scanf("%1c", &c);
        }

        if(c != '(')
            insert(&array, ' ');
            
    }

    while(!is_empty())
        //printf("%1c", (char)pop());
        insert(&array, (char)pop());

    //printf("\n");
    return array;
}

int evaluate(struct array *array){
    char c;
    int x;
    int sum = 0;

    stack_init();
    for(int i = 0; i < array->currentSize; i++){
        c = array->start[i];

        if(c == ' ')
            continue;

        x = 0;

        if(c == '+')
            x = pop() + pop(); 

        if(c == '*')
            x = pop() * pop();

        while(c>='0' && c<='9'){
            x = 10*x + (c-'0');
            i++;
            c = array->start[i];
        }
        push(x);
    }

    return x;
}
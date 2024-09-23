#include <stdio.h>
#include <stdlib.h>

static struct node **stack;
static int p;
static int currentSize = 0;
static int chuckSize = 25;

struct node {
    char info;
    struct node *left;
    struct node *right;
};

struct node *nalloc(){
    return (struct node*)malloc(sizeof(struct node));
}

void push(struct node *v){
    if(p == currentSize){
        currentSize += chuckSize;
        *stack = (struct node*)realloc(stack, currentSize*sizeof(struct node));
    }
    (stack)[p++] = v;
}

struct node* pop(){
    return stack[--p];
}

void stackinit(int size){
    if(size <= 0)
        return;
    stack = (struct node**)malloc(size*sizeof(struct node*));
    p = 0;
    currentSize += size;
}

int driver(){
    struct node *x;
    struct node *z;
    char c;
    for(stackinit(25); (c = getchar()) != EOF;){
        x = nalloc();
        x->info = c;
        x->left = z;
        x->right = z;
        if(c == '+' || c == '*'){
            x->right = pop();
            x->left = pop();
        }
        push(x);
    }

    return 1;
}

int main(){
    driver();

    putchar(10);
}
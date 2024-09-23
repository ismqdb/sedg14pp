#include <stdio.h>
#include <stdlib.h>

struct node {
    char info;
    struct node *left;
    struct node *right;
};

struct node *n_alloc(){
    return (struct node*)malloc(sizeof(struct node));
}

struct node *x;
struct node *z;
char c;

void stack_init(){
    x = n_alloc();
    z = n_alloc();


}

void push(struct node *x){

}

struct node* pop(){
    
}

int main(){
    z = n_alloc();
    z->left = z;
    z->right = z;

    for(stack_init(); (c = getchar()) != EOF;){
        x = n_alloc();
        x->info = c;
        x->left = z;
        x->right = z;
        if(c == '+' || c == '*'){
            x->right = pop();
            x->left = pop();
        }
        push(x);
    }

    putchar(10);
}
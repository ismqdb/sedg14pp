/* ******************************************************************************** */

#include <iostream>
#include <stack>
#include <queue>

#include "./Snippets/11. stack/11. stackL.hpp"
#include "./Snippets/11. stack/11. stackPA.hpp"

/* ******************************************************************************** */

template<typename T>
    void foo(stack<T>* stack){
       while(!stack->isEmpty()){
            std::cout << stack->top() << ' ';
            stack->pop();
        } 
        putchar(0xA);
    }

int main(){
    stackPA<int>* s_pa = new stackPA<int>{};
    stackL<int>* s_l = new stackL<int>{};

    s_l->push(20);
    s_l->push(30);

    s_pa->push(100);
    s_pa->push(120);

    foo(s_l);
    foo(s_pa);
}

/* ******************************************************************************** */
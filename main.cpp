/* ******************************************************************************** */

#include <iostream>
#include <stack>
#include <queue>
#include <future>

#include "Snippets/20. ruler/20. ruler.hpp"
#include "Snippets/11. stack/11. stackA.hpp"

/* ******************************************************************************** */

void f1(stackA<int>& stack){
    for(int i = 0; i < 10; i++)
        stack.push(i);
}

void f2(stackA<int> &stack){
    for(int i = 100; i < 110; i++)
        stack.push(i);
}

int main(){
    stackA<int> stack;

    std::thread t1(f1, std::ref(stack));
    std::thread t2(f2, std::ref(stack));

    t1.join();
    t2.join();

    while(!stack.isEmpty()){
        std::cout << stack.top() << '\n';
        std::flush(std::cout);
        stack.pop();
    }
/*
    rulePreorder(0, 8, 3);
    putchar(10);

    ruleInorder(0, 8, 3);
    putchar(10);

    ruleIterative(0, 8, 3);
    putchar(10); */
}

/* ******************************************************************************** */
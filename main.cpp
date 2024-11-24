/* ******************************************************************************** */

#include <iostream>
#include <stack>
#include <queue>
#include <future>

#include "Snippets/20. ruler/20. ruler.hpp"
#include "Snippets/11. stack/11. stackA.hpp"

/* ******************************************************************************** */

void f1(std::promise<int>& p1, stackA<int>& stack){
    for(int i = p1.get_future().get(); i < 10; i++)
        stack.push(i);
}

void f2(std::promise<int>& p2, stackA<int> &stack){
    for(int i = p2.get_future().get(); i < 110; i++)
        stack.push(i);
}

int main(){
    stackA<int> stack;

    std::promise<int> p1;
    p1.set_value(1);

    std::promise<int> p2;
    p2.set_value(100);

    auto t1 = std::async(f1, std::ref(p1), std::ref(stack));
    auto t2 = std::async(f2, std::ref(p2), std::ref(stack));

    t1.wait();
    t2.wait();

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
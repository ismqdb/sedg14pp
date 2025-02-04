/* ******************************************************************************** */

#include <iostream>
#include <future>
#include <thread>
#include <cmath>

#include "Snippets/00. includes/runningTimeMacros.hpp"

#include "Snippets/11. stack/11. stackA.hpp"
#include "Snippets/11. stack/11. stackL.hpp"
#include "Snippets/11. stack/11. stackPA.hpp"

/* ******************************************************************************** */

void testStackA(){
    stackA<int> stack{};
    int limit = pow(10, 7);

    for(int i = 0; i < limit; i++)
        stack.push(i);

    while(!stack.isEmpty())
        stack.pop();
}

void testStackL(){
    stackL<int> stack{};
    int limit = pow(10, 7);

    for(int i = 0; i < limit; i++)
        stack.push(i);

    while(!stack.isEmpty())
        stack.pop();
}

int main(){
    double x1;
    double x2;
    double x3;

    runningTime(testStackA(), x1);
    runningTime(testStackL(), x2);

    std::cout << "Stack array: " << x1 << ".\n";
    std::cout << "Stack linked list: " << x2 << ".\n";
}

/* ******************************************************************************** */
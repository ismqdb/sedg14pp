/* ******************************************************************************** */

#include <iostream>
#include <future>
#include <thread>
#include <cmath>

#include "Snippets/11. stack/11. stackLF.hpp"

/* ******************************************************************************** */

int main(){
    stackLF<int> stack{};

    for(int i = 0; i < 10; i++)
        stack.push(i*10);

    for(int i = 0; i < 10; i++){
        std::cout << stack.top() << '\n';
        stack.pop();
    }
}

/* ******************************************************************************** */
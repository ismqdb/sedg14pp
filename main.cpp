/* ******************************************************************************** */

#include <iostream>
#include <stack>
#include <queue>

#include "./Snippets/11. stack/11. stackL.hpp"
#include "./Snippets/10. parallel array/10. parallelArray.hpp"

/* ******************************************************************************** */

int main(){
    stackL<node<int>> stack{};

    node<int> n{20};
    stack.push(n);
    stack.isEmpty();
    stack.pop();
}

/* ******************************************************************************** */
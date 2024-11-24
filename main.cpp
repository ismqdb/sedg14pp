/* ******************************************************************************** */

#include <iostream>
#include <stack>
#include <queue>

#include "Snippets/00. includes/tree node RS/treeNodeRS.hpp"

/* ******************************************************************************** */

// A B C + D E * * F + *

int main(){
    treeNodeRS<char> *root = createNode<char>('E');

    auto a1 = insertChild(root, 'A');
    auto r1 = insertSibling(root, a1, 'R');

    int result = 0;
    externalPathLengthRS(root, 0, result);

    std::cout << result << '\n';
}

/* ******************************************************************************** */
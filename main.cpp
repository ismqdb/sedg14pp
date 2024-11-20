/* ******************************************************************************** */

#include <iostream>
#include <stack>
#include <queue>

#include "Snippets/00. includes/tree node RS/treeNodeRS.hpp"

/* ******************************************************************************** */

// A B C + D E * * F + *

int main(){
    treeNodeRS<char> *node = createNode<char>('E');

    auto a1 = insertChild(node, 'A');
    auto r1 = insertSibling(node, a1, 'R');
    auto e2 = insertSibling(node, a1, 'E');

    auto a2 = insertChild(a1, 'A');
    auto s1 = insertSibling(a1, a2, 'S');
    auto t1 = insertSibling(a1, a2, 'T');

    auto m1 = insertChild(t1, 'M');
    auto p1 = insertSibling(t1, m1, 'P');
    auto l1 = insertSibling(t1, m1, 'L');
    auto e3 = insertSibling(t1, m1, 'E');

}

/* ******************************************************************************** */
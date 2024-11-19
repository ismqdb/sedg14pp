/* ******************************************************************************** */

#include <iostream>
#include <stack>
#include <queue>

#include "Snippets/00. includes/tree node RS/treeNodeRS.hpp"

/* ******************************************************************************** */

// A B C + D E * * F + *

int main(){
    treeNodeRS<char> *node = createNode<char>('a');

    insertChild(node, 'B');
    insertSibling(node, 'C');
    insertSibling(node, 'D');
}

/* ******************************************************************************** */
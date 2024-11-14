/* ******************************************************************************** */

#include <iostream>
#include <stack>
#include <queue>

#include "./Snippets/00. includes/postfix/postfix.hpp"
#include "./Snippets/00. includes/parse tree/parseTree.hpp"

/* ******************************************************************************** */

// A B C + D E * * F + *

int main(){
    treeNode<char>* t = buildParseTree<char>();
    
    int len = 0;
    int level = 1;
    externalPathLength(t, level, len);

    std::cout << len << '\n';
}

/* ******************************************************************************** */
/* ******************************************************************************** */

#include <iostream>
#include <stack>
#include <queue>

#include "./Snippets/00. includes/n ary tree/nAryTree.hpp"

/* ******************************************************************************** */

// A B C + D E * * F + *

int main(){
    nAryTree<char> tree{};
    tree.sampleData();

    int x = tree.externalPathLength();
}

/* ******************************************************************************** */
/* ******************************************************************************** */

#include <iostream>
#include <stack>
#include <queue>

#include "./Snippets/00. includes/n ary tree/nAryTree.hpp"

/* ******************************************************************************** */

// A B C + D E * * F + *

int main(){
    nAryTree<char> *tree = new nAryTree<char>{};

    int root = tree->insert('E');

    int a1 = tree->insertChild(root, 'A');
    int r1 = tree->insertSibling(root, a1, 'R');
    int e1 = tree->insertSibling(root, r1, 'E');

    int a2 = tree->insertChild(a1, 'A');
    int s1 = tree->insertSibling(a1, a2, 'S');

    int t1 = tree->insertChild(r1, 'T');

    int m1 = tree->insertChild(t1, 'M');
    int p1 = tree->insertSibling(t1, m1, 'P');
    int l1 = tree->insertSibling(t1, p1, 'L');
    int e2 = tree->insertSibling(t1, l1, 'E');

    int x = tree->externalPathLength();
}

/* ******************************************************************************** */
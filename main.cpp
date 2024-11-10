/* ******************************************************************************** */

#include <iostream>
#include <stack>
#include <queue>

#include "./Snippets/00. includes/postfix/postfix.hpp"
#include "./Snippets/00. includes/parse tree/parseTree.hpp"

/* ******************************************************************************** */

// A B C + D E * * F + *

int main(){
    int screenWidth = 80;
    drawBinaryTreeInfo drawInfo {screenWidth};

    treeNode<char> *t = buildParseTree<char>();

    std::queue<treeNode<char>*> queue{};
    queue.push(t);

    //drawBinaryTreeIterative<char>(queue, drawInfo);
    drawBinaryTreeRecursive<char>(queue, drawInfo);
}

/* ******************************************************************************** */
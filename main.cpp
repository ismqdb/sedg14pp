/* ******************************************************************************** */

#include <iostream>
#include <future>
#include <thread>
#include <cmath>

#include "Snippets/00. includes/runningTimeMacros.hpp"
#include "Snippets/00. includes/parse tree/parseTree.hpp"

#include "Snippets/18. tree traversals/18. treeTraversals.hpp"
#include "Snippets/22. recursion removal/22. recursionRemovalPreOrder.hpp"

/* ******************************************************************************** */

int main(){
    treeNode<char> *tree = buildParseTree<char>();

    preorderRecursive(tree);
}

/* ******************************************************************************** */
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

    double x1;
    double x2;
    double x3;

    runningTime(preorderIterative<char>(tree), x1);
    putchar(10);
    runningTime(preorderRecursive<char>(tree), x2);
    putchar(10);
    runningTime(preOrderRR4(tree), x3);
    putchar(10);

    std::cout << "Pre order iterative:\t\t" << x1 * pow(10, 9) << " n seconds.\n";
    std::cout << "Pre order recursive:\t\t" << x2 * pow(10, 9) << " n seconds.\n";
    std::cout << "Pre order RR:\t\t\t\t" << x3 * pow(10, 9) << " n seconds.\n";
}

/* ******************************************************************************** */
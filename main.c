#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "./Snippets/00. includes/parse tree/parseTree.h"
#include "./Snippets/22. recursion removal/22. recursionRemovalInOrder.h"

#include "./Snippets/18. tree traversal/18. treeTraversal.h"

int main(){
    struct treeNode *t = buildParseTree();

    //inOrder(t);
    putchar(10);

    inOrderRecursive(t);
    putchar(10);
}

// A B C + D E * * F + *
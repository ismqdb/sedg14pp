#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "./Snippets/00. includes/parse tree/parseTree.h"
#include "./Snippets/22. recursion removal/22. recursionRemovalPostOrder.h"

int main(){
    struct treeNode *t = buildParseTree();

    postOrderRR0(t);
    putchar(10);

    postOrderRR1(t);
    putchar(10);
}

// A B C + D E * * F + *

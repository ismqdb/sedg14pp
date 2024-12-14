/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "./Snippets/00. includes/mass suicide/massSuicide.h"

/* ******************************************************************************** */

int main(){
    int n = 0xa;
    int m = 5;

    massSuicideArray(n, m);
    massSuicideLinkedList(n, m);
    massSuicideRecursiveDriver(n, m);
}

/* ******************************************************************************** */
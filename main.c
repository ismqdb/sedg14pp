/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "./Snippets/01. gcd/01. gcd.h"

/* ******************************************************************************** */

int main(){
    unsigned long long x = 200;
    unsigned long long y = 175;

    printf("%d\n", gcd(x, y));
    printf("%d\n", gcdRecursive(&x, &y));
}

/* ******************************************************************************** */
/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

/* ******************************************************************************** */

double formula2(int n){
    if(n < 2)
        return 0;
    else 
        return formula2(n/2) + 1;
}


int main(){
    for(int i = 2; i < 128; i *= 2)
        printf("%f %f\n", formula2(i), log(i));
}

/* ******************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

void sieve(int size){
    if(size < 2){
        fprintf(stderr, "Sieve: less than 2 elements.\n");
        return;
    }

    int i,j;
    
    int* a = (int*)malloc(size*sizeof(int));

    for(a[1]=0, i=2; i<size; i++)
        a[i]=1;

    for(i=2; i <= size/2; i++)
        for(j=2; j <= size/i; j++)
            if((i*j)<size)
                a[i*j] = 0;

    for(i = 1; i < size; i++)
        if(a[i])
            printf("%4d\n", i);

    putchar(10);
    free(a);
}
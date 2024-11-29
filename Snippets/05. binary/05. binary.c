/* ******************************************************************************** */

#include "./05. binary.h"

/* ******************************************************************************** */

int binary(int num){
   int *ptr = (int*)malloc(sizeof(int));
   int currentSize = 1;
   for(int i = 0; num>0; i++){
      *(ptr+i) = num%2;
      num/=2;
      currentSize++;
      ptr = (int*)realloc(ptr, currentSize*sizeof(int));
   }
   currentSize--;

   while(currentSize-->0)
      printf("%d", *(ptr+currentSize));
   free(ptr);
   putchar(10);
}

/* ******************************************************************************** */
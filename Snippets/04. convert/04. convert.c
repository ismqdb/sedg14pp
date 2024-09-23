#include "./04. convert.h"

int convert(){
   char c;
   unsigned long long value = 0;
   int pow = 1;

   int chunk = 5;
   int currentSize = 0;

   char* ptr = (char*)malloc(chunk);
   currentSize = chunk;
   int i;

   for(i = 0; i < currentSize; i++){
      if(i == (currentSize-1)){
         ptr = (char*)realloc(ptr, currentSize+chunk);
         currentSize += chunk;
      }

      scanf("%1c", &c);
      if(!isdigit(c) || c == ' ')
         break;
      ptr[i] = c;
   }

   if(i > 9){
      fprintf(stderr, "Overflow. Use 9 digits or less.\n");
      errno = EIO;
      return 0;
   }

   while(i-- > 0){
      value += (pow * (ptr[i] - '0'));
      pow *= 10;
   }

   return value;
}

int convert_main(){
   int x = convert();

   if(errno == 0)
      printf("%d\n", x);
}
#include <stdio.h>

int main(int argc, char *argv[]) {
   int i = 0;
   if(argc < 2)
       return 1;
 
   while(argv[1][i] != '\0')
       i++;
   printf("len: %d\n", i);
 
   return 0;
}

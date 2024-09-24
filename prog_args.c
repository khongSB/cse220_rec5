#include <stdio.h>

int main(int argc, char *argv[]) {
   int i = 0;
   while(argv[i] != NULL) {
       printf("argv[%d] = %s\n", i, argv[i]);
       i++;
   }

   printf("%p\n", argv[argc]);
   return 0;
}

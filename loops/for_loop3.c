//printing even numbers from 0 to limit

#include <stdio.h>
int main()
{
   int i, limit;
   printf("Enter the limit: ");
   scanf("%d", &limit);
   for(i=0; i<=limit; i=i+2)
   {
     
        printf("%d ", i);
    
   }
   return 0;
}

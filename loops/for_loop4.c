// printing odd numbers in reverse order from limit to 1

#include <stdio.h>
int main()
{
   /* 1. int i, limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    
    if(limit % 2 == 0)
        limit--;
    
        for(i=limit; i>=1; i=i-2)
    {
        printf("%d ", i);
    }
    printf("\n");
    return 0; */

    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    
    if(limit % 2 == 0)
        limit--;
    
        for(; limit>=1; limit=limit-2)
    {
        printf("%d ", limit);
    }
    printf("\n");
    return 0; 

}

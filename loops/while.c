#include <stdio.h>
int main()
{
    int i,limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    i = 1;
    
    while(i <= limit)
    {
        printf("%d\n ", i);
        i+=2;
    }
    return 0;
}
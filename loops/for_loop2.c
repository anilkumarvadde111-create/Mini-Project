//printing numbers in reverse order from limit to 1

#include <stdio.h>
int main()
{
    int i, limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    for(i=limit; i>=1; i--)
    {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
//printing numbers from 1 to limit

#include <stdio.h>
int main()
{
    int i, limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    for(i=1; i<=limit; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
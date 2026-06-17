#include <stdio.h>
int main()
{
    int num;
    printf("enter a number:\n");
    scanf("%d",&num);
    if(num % 2)          
                                                            
    {
        printf("%d is odd\n", num);
    }
    else
    {
        printf("%d is even\n", num);

    }

    return 0;
}
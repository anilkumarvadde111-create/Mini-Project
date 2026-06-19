//printf the power of 

#include <stdio.h>
int main()
{
    int i,number;
    printf("Enter the number:");
    scanf("%d",&number);
    if(number<0)
    return 1;
    i=1;
    while(number)
    {
         printf("%d\n ", i);
            i=i*2;
            number--;
    }
    return 0;
}
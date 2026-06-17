#include <stdio.h>

int main()
{
//initialization of variables
    int num1, num2, num3;
    scanf("%d%d%d", &num1, &num2, &num3);
    printf("Enter three numbers :%d %d %d\n", num1, num2, num3);
    int sum;
    sum=num1+num2+num3;
    printf("sum is :%d\n", sum); //we can initialise like int avg=(n1+n2+n3)/3
    int avg=sum/3;
    printf("average is :%d\n", avg);
    return 0;




}
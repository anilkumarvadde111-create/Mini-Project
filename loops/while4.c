#include <stdio.h>
int main()
{
    int i,n1,n2;
    printf("Enter the two numbers:");
    scanf("%d %d", &n1, &n2);
    int sum=0;
    for(i=0;i<n2;i++)
    {
      sum=sum+n1;
    }
    printf("%d",sum);
    return 0;
}
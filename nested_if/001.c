#include <stdio.h>
int main()
{
    int n1, n2, n3;
    printf("Enter three numbers:");
    scanf("%d%d%d", &n1, &n2, &n3);
    if(n1<n2)
    {
        if(n1<n3)
        {
          printf("n1 is smallest:%d\n", n1);
        }
        else
        {
            printf("n2 is smallest:%d\n", n2);
        }
    }
    else
    {
        if(n2<n3)
        {
            printf("n2 is smallest:%d\n", n2);
        }
        else
        {
            printf("n3 is smallest:%d\n", n3);
        }
    }
    return 0;
}
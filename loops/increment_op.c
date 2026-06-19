#include <stdio.h>
int main()
{

    int n1=10, n2=10;

    int r1=++n1; // pre increment(value will be updated at same time)
    int r2=n2++; // post increment(value will be updated at next call)

    printf("n1=%d\nn2=%d\nr1=%d\nr2=%d\n", n1, n2, r1, r2); // n1=11, n2=10, r1=11, r2=10   
    return 0;
}

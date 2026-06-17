#include <stdio.h>
int main()
{
    unsigned char ch1 =-1;   // for unsigned and signed example program
    printf("ch1 = %d\n", ch1);

    ch1 = 256;
    printf("ch1 = %d\n", ch1);

    char ch2 = 300;       // here  for signed deleration no need to mension the sign
    printf("ch2 = %d\n", ch2);

    ch2 = -300;
    printf("ch2 = %d\n", ch2);
    
    return 0;
}
//print sum of even numbers from 2 to n
#include <stdio.h>
int main()
{
 int i,number,sum=0;
 printf("Enter the number:");
 scanf("%d",&number);
 i=2;
 while(i <= number)
 {
    sum += i;
   
    i+=2;   //i=i+2

}
 printf(" sum is %d\n ",sum);
 return 0;
}
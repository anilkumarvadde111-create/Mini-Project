#include <stdio.h>
int main()
{

int num1, num2;
char op;
//printf("Enter num1,op and num2:");
scanf("%d%c%d",&num1, &op, &num2);
if(num2==0 && op=='/')
{
  printf("We cannot divide a number by zero\n"); 
  return 0;
}


switch(op)
{
   case '+':
   printf("sum=%d\n", num1+num2);  // or printf("Addition of %d and %d is %d\n", num1, num2, num1+num2);
   break;
    case '-':
   printf("diff=%d\n", num1-num2);
   break;
    case '*':
   printf("mul=%d\n", num1*num2);
   break;
    case '/':
   printf("div=%g\n", (float)num1/num2);
   break;
   default:
   printf("Invalid expression");
}

return 0;

}
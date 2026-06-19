#include <stdio.h>
int main()
{
    int number,reverse=0;
    
    printf("Enter the number:");
    scanf("%d",&number);
    while(number>0)
    {
        reverse=reverse%10+number*10;
        number=number/10;
       
    }
    printf("Reverse of the number is: %d\n", reverse);
    if(reverse == number)
    {
        printf("The number is a palindrome.\n");
    }
    else
    {
        printf("The number is not a palindrome.\n");
    }
    return 0;
}


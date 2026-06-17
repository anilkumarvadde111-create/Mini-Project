#include <stdio.h>
int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    switch(num)
    {
        case 10:
            printf("You entered num Ten\n");
            break;           // if we not use break statement then it will execute all the cases after the matched case
        case 20:
            printf("You entered num Twenty\n");
            break;
        case 30:
            printf("You entered num Thirty\n");
            break;
        default:
            printf("Invalid input\n");
    }
    return 0;
}
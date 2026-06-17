#include <stdio.h>

int main() {
    char ch;
    printf("Enter character:");
    scanf("%c", &ch);
    if(ch>='A' && ch<='Z')
    {
        printf("You entered character is: UpperCase\n");
    }
    else if(ch>='a' && ch<='z')
    {
        printf("You entered character is: LowerCase\n");
    }
    else if(ch>='0' && ch<='9')
    {
        printf("You entered character is: digit\n");
    }
    else
    {
        printf("You entered character is: Symbol\n");
    }
    return 0;
}
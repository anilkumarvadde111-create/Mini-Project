#include <stdio.h>

int main()
{
    char op;

    printf("<--------Welcome to my Dhaba---------> \n\n");
    printf("select what you want-> \n");
    printf("1. starter\n2. Main course\n3. Dessert\n4. Exit\n");

    scanf("%c", &op);


    switch(op)
    {
       case '1':
       printf("You have choosed starters\n");
       printf("1.DC\n2. PP\n3. CT\n4. Exit\n");
        break;
       case '2':
       printf("You have choosed Main course\n");
       printf("1.\n2. \n3. \n4. Exit\n");
         break;
        case '3':
       printf("You have choosed Dessert\n");
       printf("1.\n2. \n3. \n4. Exit\n");
        break;
        case '4':
       printf("You have choosed Exit\n");
       printf("Come again soon\n");
       break;
       default:
         printf("Invalid choice\n");
       
       
    }
}
#include <stdio.h>

int main()
{
    char op, ch;

    printf("<--------Welcome to my Dhaba---------> \n\n");
    printf("select what you want-> \n");
    printf("1. starter\n2. Main course\n3. Dessert\n4. Exit\n");

    scanf("%c", &op);


    switch(op)
    {
       case '1':
       printf("You have choosed starters\n");
       printf("1.DC\n2. PP\n3. CT\n4. Exit\n");
       scanf(" %c", &ch);
        switch(ch)
        {
            case '1':
            printf("You have choosed DC\n");
            break;
            case '2':
            printf("You have choosed PP\n");
            break;
            case '3':
            printf("You have choosed CT\n");
            break;
            case '4':
            printf("You have choosed Exit\n");
            break;
            default:
            printf("Invalid choice\n");
        }
        break;
       case '2':
       printf("You have choosed Main course\n");
       printf("1.CB\n2. CC\n3. CF\n4. Exit\n");
       scanf(" %c", &ch); 
         switch(ch)
        {
            case '1':
            printf("You have choosed CB\n");
            break;
            case '2':
            printf("You have choosed CC\n");
            break;
            case '3':
            printf("You have choosed CF\n");
            break;
            case '4':
            printf("You have choosed Exit\n");
            break;
            default:
            printf("Invalid choice\n");
         }
         break;
        case '3':
       printf("You have choosed Dessert\n");
       printf("1. Ice Cream\n2. Cake\n3. Pastry\n4. Exit\n");
       scanf(" %c", &ch);
          switch(ch)
          {
              case '1':
              printf("You have choosed Ice Cream\n");
              break;
              case '2':
              printf("You have choosed Cake\n");
              break;
              case '3':
              printf("You have choosed Pastry\n");
              break;
              case '4':
              printf("You have choosed Exit\n");
              break;
              default:
              printf("Invalid choice\n");
          } 
        break;
        case '4':
       printf("You have choosed Exit\n");
       printf("Come again soon\n");
       break;
       default:
         printf("Invalid choice\n");
       
       
    }
    return 0;
}

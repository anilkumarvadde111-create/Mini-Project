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
       printf("1.Dragon Chicken\n2. Chicken Pista\n3. Chicken Tikka\n4. Exit\n");
       scanf(" %c", &ch);
        switch(ch)
        {
            case '1':
            printf("You have choosed Dragon Chicken\n");
            break;
            case '2':
            printf("You have choosed Chicken Pista\n");
            break;
            case '3':
            printf("You have choosed Chicken Tikka\n");
            break;
            case '4':
            printf("Exit\n");
            break;
            default:
            printf("Invalid choice\n");
        }
        break;
       case '2':
       printf("You have choosed Main course\n");
       printf("1.Chicken Biryani\n2. Chicken Curry\n3. Chicken Fry\n4. Exit\n");
       scanf(" %c", &ch); 
         switch(ch)
        {
            case '1':
            printf("You have choosed Chicken Biryani\n");
            break;
            case '2':
            printf("You have choosed Chicken Curry\n");
            break;
            case '3':
            printf("You have choosed Chicken Fry\n");
            break;
            case '4':
            printf("Exit\n");
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
              printf("Exit\n");
              break;
              default:
              printf("Invalid choice\n");
          } 
        break;
        case '4':
       printf(" Exit from the menu\n");
       printf("Come again soon\n");
       break;
       default:
         printf("Nothing ordered\n");
       
       
    }
    return 0;
}

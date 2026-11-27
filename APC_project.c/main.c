#include "apc.h"

int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL;
    node *head2 = NULL, *tail2 = NULL;
    node *headR = NULL, *tailR = NULL;

    if (cla_validation(argc, argv) == FAILURE)
    {
        printf("Invalid command-line arguments\n");
        return FAILURE;
    }

  int sign1=1,sign2=1;
char *num1=argv[1],*num2=argv[3];
if(num1[0]=='-')
{
    sign1=-1;
    num1++;
}
if(num2[0]=='-')
{
    sign2=-1;
    num2++;
}
create_list(num1,&head1,&tail1);
create_list(num2,&head2,&tail2);

    char opr = argv[2][0];

    switch (opr)
    {
      case '+':
      {
        int cmp=compare_list(head1,head2);
        if(sign1==sign2)
        {
          addition(tail1,tail2,&headR,&tailR);
          if(sign1==-1)printf("-");
         } 
        else
        {
           if(cmp==SAME)
            insert_first(&headR,&tailR,0);
           else if(cmp==OPERAND1)
           {
             subtraction(tail1,tail2,&headR,&tailR);
             if(sign1==-1)printf("-");
            }
           else
           {
              subtraction(tail2,tail1,&headR,&tailR);
             if(sign2==-1)printf("-");
           }
        } 
         break;
      }

      case '-':
      {
        int cmp=compare_list(head1,head2);
        if(sign1!=sign2)
        {
          addition(tail1,tail2,&headR,&tailR);
          if(sign1==-1)printf("-");
        }
        else
        {
          if(cmp==SAME)
            insert_first(&headR,&tailR,0);
          else if(cmp==OPERAND1)
          {
              subtraction(tail1,tail2,&headR,&tailR);
              if(sign1==-1)printf("-");
          }
          else
          {
             subtraction(tail2,tail1,&headR,&tailR);
              if(sign1==1)printf("-");
         }
       }
       break;
     }

        case 'x':
        {
            multiplication(tail1, tail2, &headR, &tailR);
             if(sign1*sign2<0)printf("-");
            break;
        }

        case '/':
        {
            division(head1, head2, &headR, &tailR);
              if(sign1*sign2<0)printf("-");
            break;
        }
		case '%':
        {
            modulo(head1,head2,&headR,&tailR);
     if (sign1 == -1 && !(headR->data == 0 && headR->next == NULL))
        printf("-");

             break;
        }
        default:
            printf("Invalid operator\n");
            delete_list(&head1, &tail1);
            delete_list(&head2, &tail2);
            return FAILURE;
    }

    remove_pre_zeros(&headR);
    print_list(headR);

    delete_list(&head1, &tail1);
    delete_list(&head2, &tail2);
    delete_list(&headR, &tailR);

    return SUCCESS;
}

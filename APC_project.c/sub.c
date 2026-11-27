#include "apc.h"                                        // Header file inclusion

void subtraction(node *tail1,node *tail2,node **headR,node **tailR)
{
    int sub,borrow=0;                                   // Variables to store subtraction result and borrow

    while(tail1!=NULL)                                  // Traverse first number from LSD to MSD
    {
        sub=tail1->data-borrow;                         // Subtract previous borrow from current digit

        if(tail2!=NULL)                                 // Check if second number has a digit
        {
            sub-=tail2->data;                           // Subtract digit of second number
            tail2=tail2->prev;                          // Move to previous digit of second number
        }

        if(sub<0)                                       // Check if borrow is required
        {
            sub+=10;                                    // Adjust result by adding 10
            borrow=1;                                   // Set borrow for next digit
        }
        else
            borrow=0;                                   // No borrow required

        insert_first(headR,tailR,sub);                  // Insert result digit at beginning of result list

        tail1=tail1->prev;                              // Move to previous digit of first number
    }

    remove_pre_zeros(headR);                            // Remove leading zeros from result
}
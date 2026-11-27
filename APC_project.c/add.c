#include "apc.h"                              // Header file inclusion

void addition(node *tail1,node *tail2,node **headR,node **tailR) // Function definition
{
    int sum,carry=0;                          // Variables to store sum and carry

    while(tail1!=NULL||tail2!=NULL||carry!=0) // Continue until all digits and carry are processed
    {
        sum=carry;                            // Initialize sum with previous carry

        if(tail1!=NULL)                       // Check if first list has a digit
        {
            sum+=tail1->data;                 // Add digit from first list
            tail1=tail1->prev;                // Move to previous node
        }

        if(tail2!=NULL)                       // Check if second list has a digit
        {
            sum+=tail2->data;                 // Add digit from second list
            tail2=tail2->prev;                // Move to previous node
        }

        carry=sum/10;                         // Calculate carry for next iteration

        insert_first(headR,tailR,sum%10);     // Insert current digit into result list
    }
}
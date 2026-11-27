#include "apc.h"                                      // Header file inclusion

void division(node *head1,node *head2,node **headR,node **tailR) // Function to perform division
{
    int divisor=0,partial=0,digit;                    // Variables for divisor, partial dividend and quotient digit

    node *temp=head2;                                 // Temporary pointer for second number

    while(temp!=NULL)                                 // Convert divisor list into integer
    {
        divisor=divisor*10+temp->data;                // Form divisor digit by digit
        temp=temp->next;                              // Move to next node
    }

    while(head1!=NULL)                                // Traverse dividend list
    {
        partial=partial*10+head1->data;              // Build partial dividend

        digit=partial/divisor;                        // Find quotient digit

        partial=partial%divisor;                      // Update remainder

        if(*headR!=NULL||digit!=0)                    // Avoid leading zeros in result
            insert_last(headR,tailR,digit);           // Store quotient digit in result list

        head1=head1->next;                            // Move to next dividend digit
    }

    if(*headR==NULL)                                  // If quotient is zero
        insert_last(headR,tailR,0);                   // Store 0 in result list
}
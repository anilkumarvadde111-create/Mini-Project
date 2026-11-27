#include "apc.h"                                            // Header file inclusion

void multiplication(node *tail1,node *tail2,node **headR,node **tailR) // Function to perform multiplication
{
    int len1=0,len2=0,i,j,carry,product;                   // Variables for lengths, indices, carry and product

    node *p,*q;                                            // Temporary pointers

    for(p=tail1;p!=NULL;p=p->prev) len1++;                 // Calculate length of first number

    for(p=tail2;p!=NULL;p=p->prev) len2++;                 // Calculate length of second number

    int result[len1+len2];                                 // Array to store intermediate result

    for(i=0;i<len1+len2;i++) result[i]=0;                  // Initialize result array with zeros

    i=0;                                                  
    for(p=tail1;p!=NULL;p=p->prev,i++)                     // Traverse first number from LSD to MSD
    {
        carry=0;                                           // Reset carry for each digit multiplication

        j=0;                                               
        for(q=tail2;q!=NULL;q=q->prev,j++)                 // Traverse second number from LSD to MSD
        {
            product=p->data*q->data+result[i+j]+carry;     // Multiply digits and add previous result

            result[i+j]=product%10;                        // Store current digit

            carry=product/10;                              // Calculate carry
        }

        result[i+j]+=carry;                                // Add remaining carry
    }

    for(i=len1+len2-1;i>=0;i--)                            // Traverse result array in reverse order
        insert_last(headR,tailR,result[i]);               // Store result in linked list

    remove_pre_zeros(headR);                               // Remove leading zeros from result
}
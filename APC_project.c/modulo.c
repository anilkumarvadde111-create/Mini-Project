#include "apc.h"

void modulo(node *head1,node *head2,node **headR,node **tailR)
{
    node *remH=NULL,*remT=NULL;
    node *temp;
    int cmp;
    for(temp=head1;temp!=NULL;temp=temp->next)
        insert_last(&remH,&remT,temp->data);
    remove_pre_zeros(&remH);
    remove_pre_zeros(&head2);
    while(1)
    {
        cmp=compare_list(remH,head2);
        if(cmp==OPERAND2||cmp==SAME)
        {
            if(cmp==SAME)
                delete_list(&remH,&remT);
            break;
        }
        node *newH=NULL,*newT=NULL;
        subtraction(remT,({node *p=head2;while(p->next)p=p->next;p;}),&newH,&newT);
        delete_list(&remH,&remT);
        remH=newH;
        remT=newT;
    }
    *headR=NULL;
    *tailR=NULL;
    for(temp=remH;temp!=NULL;temp=temp->next)
        insert_last(headR,tailR,temp->data);
    if(*headR==NULL)
        insert_last(headR,tailR,0);
    delete_list(&remH,&remT);
}
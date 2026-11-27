#include "apc.h"

//command_line arguments validation

#include "apc.h"
int cla_validation(int argc,char *argv[])
{
    int i,j;
    if(argc!=4)return FAILURE;
    if(argv[2][1]!='\0')return FAILURE;
    if(argv[2][0]!='+'&&argv[2][0]!='-'&&argv[2][0]!='*'&&argv[2][0]!='x'&&argv[2][0]!='/'&&argv[2][0]!='%')return FAILURE;
    for(i=1;i<=3;i+=2)
    {
        if(argv[i][0]=='\0')return FAILURE;
        j=(argv[i][0]=='-')?1:0;
        if(argv[i][j]=='\0')return FAILURE;
        for(;argv[i][j]!='\0';j++)
            if(argv[i][j]<'0'||argv[i][j]>'9')return FAILURE;
    }
    if((argv[2][0]=='/'||argv[2][0]=='%')&&argv[3][0]=='0'&&argv[3][1]=='\0')return FAILURE;
    return SUCCESS;
}

//creat list function


void create_list(char *opr,node **head,node **tail)
{
    int i = 0;

    while (opr[i] !='\0')
    {
        insert_last(head, tail, opr[i]-'0');
        i++;
    }
}

//insert_last function

int insert_last(node **head,node **tail, int data)
{
    node *new = malloc(sizeof(node));

    if (new==NULL)
        return FAILURE;

    new->data = data;
    new->prev = *tail;
    new->next=NULL;

    if (*head==NULL)
    {
        *head=new;
        *tail=new;
        return SUCCESS;
    }

    (*tail)->next=new;
    *tail=new;

    return SUCCESS;
}

//insert first function

int insert_first(node **head,node **tail,int data)
{
    node *new=malloc(sizeof(node));
    if(new==NULL)
        return FAILURE;
    new->data=data;
    new->prev=NULL;
    new->next=*head;
    if(*head==NULL)
        *tail=new;
    else
        (*head)->prev=new;
    *head=new;
    return SUCCESS;
}

//Delete list function

int delete_list(node **head,node **tail)
{
    node *temp;
    while(*head!=NULL)
    {
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }
    *tail=NULL;
    return SUCCESS;
}

//print list

void print_list(node *head)
{
    while(head!=NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
    printf("\n");
}

//length of list

int list_len(node *head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}

//compare list function

int compare_list(node *head1,node *head2)
{
    int len1=list_len(head1);
    int len2=list_len(head2);
    if(len1>len2)return OPERAND1;
    if(len2>len1)return OPERAND2;
    while(head1!=NULL&&head2!=NULL)
    {
        if(head1->data>head2->data)return OPERAND1;
        if(head2->data>head1->data)return OPERAND2;
        head1=head1->next;
        head2=head2->next;
    }
    return SAME;
}

//remove pre_zeroes function

void remove_pre_zeros(node **head)
{
    while(*head!=NULL&&(*head)->data==0&&(*head)->next!=NULL)
    {
        node *temp=*head;
        *head=(*head)->next;
        (*head)->prev=NULL;
        free(temp);
    }
}




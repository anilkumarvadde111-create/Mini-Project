#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"

 
void initialize(AddressBook *addressBook) 
{
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}
 

 //function to validate name,phone and email
 int validate_name(char *name)
{
    //validation for name
    while(*name !='\0')
    {
        if(!((*name>='A' && *name<='Z') ||(*name>='a' && *name<='z') ||(*name==' ') ||(*name=='.')))
        {
           
         return 0;   //invalid
        }
        name++;
    }
    return 1;   //valid
}
int validate_phone(char *phone, AddressBook *addressbook)
{
    //validation for phone number
    int len=strlen(phone);
    if(len!=10)
    {

        return 0;  //invalid
    }
    for(int i=0;i<len;i++)
    {
        if(phone[i]<'0' || phone[i]>'9')
        {
           
            return 0;  //invalid
        }
    }

       
     for(int i=0;i<addressbook->contactCount;i++)
     {
         if(strcmp(phone,addressbook->Contacts[i].phone)==0)
          {
            printf("Phone number already exists !\n");
             return 0;  //invalid
           }
    }
       

    
    return 1;  // valid
}
 
int validate_email(char *email,AddressBook *addressbook)
{
    //validation for email
    int i,at=0,dot=0;
   for(i=0;email[i]!='\0';i++)
    {
        for(int i=0;i<addressbook->contactCount;i++)
        {
            if(strcmp(email,addressbook->Contacts[i].email)==0)
            {
                printf("Email already exists\n");
                return 0;  //invalid
            }
        }
        if(email[i]=='@')
        {
          at=1;
        }
        else if(email[i]=='.')
        {
          dot=1;
        }
         else if(!((email[i]>='a' && email[i]<='z') || (email[i]>='0' && email[i]<='9')))
        {
            return 0;  //invalid
        }
     

    }
     if(at==0 || dot==0)
      {
        return 0;
      }
    
    return 1;  //valid
}
 
 // Function to search contact by name,phone and email
 int search_by_name(AddressBook *addressbook)
  {
    int found=0;
    int i,index;
     printf("\nSearch by name:\n");
     char name[20];
     printf("Enter the name :");
     scanf(" %[^\n]",name);

     
     for(i=0;i<addressbook->contactCount;i++)
      {
        if(strcmp(addressbook->Contacts[i].name,name) ==0)
          {
             found++;
             index=i;
           }
      }
      if(found==0)
        {
          printf("No contact found !\n");
          return -1; //not found
        }
      else if(found==1)
        {
          printf("single contact found.\n");
          printf("\n-------------------------------------------------------------------------\n");
          printf("|%-5s       |%-20s      |%-15s      |%-30s\n ","S.NO", "NAME", "PHONE","EMAIL");
          printf("\n--------------------------------------------------------------------------\n");    
          printf("|%-5d       |%-20s      |%-15s      |%-30s\n ",index+1,addressbook->Contacts[index].name,
                       addressbook->Contacts[index].phone,addressbook->Contacts[index].email);
          printf("- --------------------------------------------------------------------------\n");             
           return index;  //single contact found
        }
      else
        {
          printf("-----Multiple contacts found-----\n");
          printf("\n-------------------------------------------------------------------------\n");
          printf("|%-5s     |%-20s      |%-15s      |%-30s\n ","S.NO", "NAME", "PHONE","EMAIL");
          printf("----------------------------------------------------------------------------\n");

          for(i=0;i<addressbook->contactCount;i++)
            {
              if(strcmp(addressbook->Contacts[i].name,name) ==0)
                {
                   
                  printf("|%-5d     |%-20s      |%-15s      |%-30s\n ",i+1,addressbook->Contacts[i].name,
                           addressbook->Contacts[i].phone,addressbook->Contacts[i].email);
                         
                }
            }
             printf("---------------------------------------------------------------------------\n"); 
             int result=search_by_phone(addressbook);  //searching by phone because multi contacts present
             return result;
        }   
  }
  int search_by_phone(AddressBook *addressbook)
  {

    int i;
    printf("\nSearch by phone:\n");
    char phone[15];
    printf("Enter the number :");
    scanf(" %[^\n]",phone);
    for(i=0;i<addressbook->contactCount;i++)
      {
        if(strcmp(addressbook->Contacts[i].phone,phone) ==0)
          {
            printf("-------Contact found-------\n");
            printf("\n----------------------------------------------------------------------\n");
            printf("|%-5s       |%-20s      |%-15s      |%-30s\n ","S.NO", "NAME", "PHONE","EMAIL");
            printf("----------------------------------------------------------------------\n");  
            printf("|%-5d       |%-20s      |%-15s      |%-30s\n ",i+1,addressbook->Contacts[i].name,
                    addressbook->Contacts[i].phone,addressbook->Contacts[i].email);
            printf("--------------------------------------------------------------------------\n");        
    
              return i;  //single contact found
          }
             
       }
       
            printf("No contact found !\n");
            return -1; //not found
            
  }
  int search_by_email(AddressBook *addressbook)
  {
    int i;
    
    printf("\nSearch by email :\n");
    char email[30];
    printf("Enter the email :");
    scanf(" %[^\n]",email);
    for(i=0;i<addressbook->contactCount;i++)
    {
        if(strcmp(addressbook->Contacts[i].email,email) ==0)
        {
             printf("----Contact found----\n");
             printf("\n----------------------------------------------------------------------\n");
             printf("|%-5s       |%-20s      |%-15s      |%-30s\n ","S.NO", "NAME", "PHONE","EMAIL");
             printf("------------------------------------------------------------------------\n");  
             printf("|%-5d       |%-20s      |%-15s      |%-30s\n ",i+1,addressbook->Contacts[i].name,
                    addressbook->Contacts[i].phone,addressbook->Contacts[i].email);
             printf("---------------------------------------------------------------------------\n");       
               
              return i;  //single contact found
        }
    }
    
        printf("No contact found !\n");
        return -1; //not found
    
  }

  //edit contact functions-->by name,phone,email
  void edit_name(AddressBook *addressbook,int index)
  {
    if(index<0)
    {
        printf("No contact found to edit !\n");
        return;
    }
    else
    { 
    
    char name[20];
    do
    {
        printf("Enter the new name :");
        scanf(" %[^\n]",name);
        if(validate_name(name)==0)
        {
            printf("Invalid name ! Enter again.\n");
        }

    } while(validate_name(name)==0); 
        
    strcpy(addressbook->Contacts[index].name,name);
    printf("---Name is updated successfully---\n");
    }
  }
  void edit_phone(AddressBook *addressbook,int index)
  {
    if(index<0)
    {
        printf("No contact found to edit !\n");
        return;
    }
    else
    { 
    char phone[15];
    do {    
        printf("Enter the new phone number :");
        scanf(" %[^\n]",phone);

        if(validate_phone(phone,addressbook)==0)
        {
         printf("Invalid phone number ! Enter again.\n");
        }

       } while(validate_phone(phone,addressbook)==0);
         
     strcpy(addressbook->Contacts[index].phone,phone);
     printf("---Phone number is updated successfully---\n");
    }
  }
  void edit_email(AddressBook *addressbook,int index)
  {
    if(index<0)
    {
        printf("No contact found to edit !\n");
        return;
    }
    else
    {
    
    char email[30];
    do{
        printf("Enter the new email :");
        scanf(" %[^\n]",email);

        if(validate_email(email,addressbook)==0)
        {
           printf("Invalid email ! Enter again.\n");
        }
      } while(validate_email(email,addressbook)==0);
        
       strcpy(addressbook->Contacts[index].email,email);
       printf("---Email is updated successfully---\n");
    
      }  
  }

  void createContact(AddressBook *addressbook)
{
    char name[20];
    char phone[15];
    char email[30];
    int i=addressbook->contactCount;
    do
    {
        printf("Enter the name :");
        scanf(" %[^\n]",name);
        if(validate_name(name)==0)
        {
            printf("Invalid name ! Enter again.\n");
        }

    } while(validate_name(name)==0); 
        
    printf("---Name is saved successfully---\n");
    do {    
        printf("Enter the phone number :");
        scanf(" %[^\n]",phone);

        if(validate_phone(phone,addressbook)==0)
        {
         printf("Invalid phone number ! Enter again.\n");
        }

    } while(validate_phone(phone,addressbook)==0);
         
     printf("---Phone number is saved successfully---\n");
       do{
        printf("Enter the email :");
        scanf(" %[^\n]",email);

        if(validate_email(email,addressbook)==0)
        {
           printf("Invalid email ! Enter again.\n");
        }
       } while(validate_email(email,addressbook)==0);
        
       printf("---Email is saved successfully---\n");

      
        strcpy(addressbook->Contacts[i].name,name);

        strcpy(addressbook->Contacts[i].phone,phone);
    
        strcpy(addressbook->Contacts[i].email,email);

        addressbook->contactCount++;
   
}

int searchContact(AddressBook *addressbook)
{
   int choice;
   int index;
   printf("You are searching for a contact");
   printf("\nSearch by\n1.Name\n2.Phone\n3.Email\n4.Back\n");
   while(1)
   {
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
          case 1:
             index=search_by_name(addressbook);
             return index;
            break;
          case 2:
            index=search_by_phone(addressbook);
            return index;
            break;
          case 3:
            index=search_by_email(addressbook);
            return index;
            break;
          case 4:
            printf("Exiting search contacts\n");
            return -1;
            break;
            
          default:
            printf("Invalid choice ! Enter again.\n");
            return -2;

        }
    }
}
void editContact(AddressBook *addressbook)
{
  printf("You can edit contact by searching\n");
  int index=searchContact(addressbook);
  
    printf("Editing contact by:\n1.Name\n2.Phone\n3.Email\n4.Back\n");
    int choice;
    while(1)
    {
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
          case 1:
            edit_name(addressbook,index); 
            break;
            case 2:
            edit_phone(addressbook,index);
            break;
            case 3:
            edit_email(addressbook,index);
            break;
            case 4:
            printf("Exiting from editing contact\n");
            return;
            break;
            default:
            printf("Invalid choice !\n");
            return;
            break;
        }
    }
}
void deleteContact(AddressBook *addressbook)
{
  printf("Delete contact\n");
  printf("You can delete contact by searching\n");
  int index=searchContact(addressbook);
  if(index<0)
  {
    printf("No contact found to delete !\n");
    return;
  }
  for(int i=index;i<addressbook->contactCount-1;i++)
   {
     addressbook->Contacts[i]=addressbook->Contacts[i+1];
   }
  addressbook->contactCount--;

  printf("Contact deleted successfully.\n");
}
void listContacts(AddressBook *addressbook)
{
  printf("List of contacts :\n");
  if(addressbook->contactCount==0)
  {
    printf("No contacts found !\n");
    return;
  }
  for(int i=0;i<addressbook->contactCount-1;i++)
  {
    for(int j=i+1;j<addressbook->contactCount;j++)
    {
      if(strcmp(addressbook->Contacts[i].name,addressbook->Contacts[j].name)>0)
      {
      Contact temp;

      temp=addressbook->Contacts[i];
      addressbook->Contacts[i]=addressbook->Contacts[j];
      addressbook->Contacts[j]=temp;
      }
    }
  }
  printf("\n--------------------------------------------------------------------------------\n");
  printf("|%-5s      |%-20s     |%-15s     |%-30s\n","S.NO", "NAME", "PHONE","EMAIL");
  printf("----------------------------------------------------------------------------------\n");
  for(int i=0;i<addressbook->contactCount;i++)
  {
    printf("|%-5d      |%-20s     |%-15s     |%-30s\n",i+1,addressbook->Contacts[i].name,addressbook->Contacts[i].phone,addressbook->Contacts[i].email);

  }
  printf("-----------------------------------------------------------------------------------\n");
}



  
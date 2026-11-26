 /* Name :- Vadde Anil Kumar
project starting and ending dates :-2026-july-31 and 2026-August-8


PROJECT Discription :-
**Address Book Management System**

Developed a menu-driven Address Book application in **C** to create, search, edit, delete, 
and display contact details with input validation and duplicate checking.

**Technologies:** 

C, Structures, Arrays, Pointers, String Handling, File Handling 

**Key Responsibilities:** 

Implemented operations like, validation, contact searching, and data storage. */




#include <stdio.h>
#include <string.h>
#include "contact.h"


int main()
{
   
    AddressBook addressbook;
    initialize(&addressbook);
     int choice;
   
    while(1)
    {
         printf("--------- \\ Address Book \\----------\n");
    
        printf("\n1.Create contact\n2.Search contact\n3.Edit contact\n4.Delete contact\n5.List contacts\n6.Save and exit\n");
        printf("\nEnter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            createContact(&addressbook);
            break;
            case 2:
            searchContact(&addressbook);
            break;
            case 3:
            editContact(&addressbook);
            break;
            case 4:
            deleteContact(&addressbook);
            break;
            case 5:
            listContacts(&addressbook);
            break;
            case 6:
            saveContactsToFile(&addressbook);
            printf("Contacts saved successfully.\n");
            return 0;
            default:
            printf("Invalid choice ! Enter again.");
        }
    }

}
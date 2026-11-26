#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact Contacts[MAX_CONTACTS];
    int contactCount; 
} AddressBook;

void createContact(AddressBook *addressBook);
int searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);

//validation functions declarations
int validate_name(char *name);
int validate_phone(char *phone, AddressBook *addressBook);
int validate_email(char *email, AddressBook *addressBook);

//Search functions declarations
int search_by_name(AddressBook *addressBook);
int search_by_phone(AddressBook *addressBook);
int search_by_email(AddressBook *addressBook);


#endif
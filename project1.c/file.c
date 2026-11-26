#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
  FILE *fp;
  fp = fopen("contacts.csv", "w");
  fprintf(fp, "#%d\n", addressBook->contactCount);
  for(int i = 0; i<addressBook->contactCount; i++)
  {
   fprintf(fp, "%s,%s,%s\n",addressBook->Contacts[i].name,addressBook->Contacts[i].phone,addressBook->Contacts[i].email);
  }
  fclose(fp);
}

void loadContactsFromFile(AddressBook *addressBook) {
  FILE *fp;
  if((fp = fopen("contacts.csv", "r")) == NULL)
  {
    fprintf(stderr,"Can't access file contacts.csv!\n");
    return;
  }
  fscanf(fp, "#%d\n", &addressBook->contactCount);
  for(int i = 0; i<addressBook->contactCount; i++)
  {
    fscanf(fp, "%[^,],%[^,],%[^\n]\n", addressBook->Contacts[i].name,addressBook->Contacts[i].phone,addressBook->Contacts[i].email);
  }
  fclose(fp);
}
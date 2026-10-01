#include <stdio.h>
#include <string.h>
#include "suppliers.h"

static supplier
suppliers[MAX_SUPPLIERS];
static int supplierCount = 0;

void addSupplier(void)
{
    if (supplierCount >= MAX_SUPPLIERS){
        printf("Maximum number of suppliers reached.\n");
        return;
    }
    supplier *s = &suppliers[supplierCount];
 printf("\n--- Add Supplier---\n");
 printf("Enter Supplier ID: ");
 scanf("%d", &s->supplierID);
getchar(); // remove newline left by scan("Enter Supplier Name ");

printf("Enter Supplier Name: ");
fgets(s->name, sizeof(s->name), stdin);
 s->name[strcspn(s->name, "\n")] = '\0';

printf("Enter Email: ");
fgets(s->email, sizeof(s->email), stdin);
s->email[strcspn(s->email, "\n")] = '\0';

printf("Enter Telephone: ");
fgets(s->telephone, sizeof(s->telephone), stdin);
s->telephone[strcspn(s->telephone, "\n")] = '\0';


  printf("Enter Town: ");
fgets(s->town, sizeof(s->town), stdin);
s->town[strcspn(s->town, "\n")] = '\0';

supplierCount++;

prinf("\nSupplier added successfully!\n");
}

void displaySuppliers(void)
{
  if (supplierCount == 0)
{
printf("\nNo suppliers registered.\n");
return;
}
  printf("\n========== REGISTERED SUPPLIERS ==========\n");

  for (int i = 0; i < supplierCount; i++)
{
    printf("\nSupplier %d\n", i + 1);
printf("Supplier ID : %d\n", suppliers[i].supplierID);
printf("Name : %s\n", suppliers[i].name);
printf("Email : %s\n", suppliers[i].email);
printf("Telephone : %s\n", suppliers[i].telephone);
printf("Town : %s\n", suppliers[i].town);
}
}

void searchSupplier(void)
{
int searchID;
int found = 0;

if (supplierCount == 0)
{
printf("\nNo suppliers registered.\n");
return;
}
printf("\n====================================\n");
printf(" SEARCH SUPPLIER\n");
printf("====================================\n");

printf("Enter Supplier ID: ");
scanf("%d", &searchID);

for (int i = 0; i < supplierCount; i++)
{
if (suppliers[i].supplierID == searchID)
{
printf("\nSupplier Found!\n");
printf("------------------------------------\n");
printf("Supplier ID : %d\n", suppliers[i].supplierID);
printf("Name : %s\n", suppliers[i].name);
printf("Email : %s\n", suppliers[i].email);
printf("Telephone : %s\n", suppliers[i].telephone);
printf("Town : %s\n", suppliers[i].town);
printf("------------------------------------\n");

found = 1;
break;
}
}

if (found == 0)
{
printf("\nSupplier with ID %d was not found.\n", searchID);
}
}

void supplierMenu(void)
{
int choice;

do
{

printf("\n====================================\n");
printf(" SUPPLIER MANAGEMENT\n");
printf("====================================\n");
printf("1. Add Supplier\n");
printf("2. Display Suppliers\n");
printf("3. Search Supplier\n");
printf("4. Return to Main Menu\n");
printf("====================================\n");
printf("Enter your choice: ");

scanf("%d", &choice);

switch (choice)
{
case 1:
addSupplier();
break;
case 2:
displaySuppliers();
break;

case 3:
searchSupplier();
break;

case 4:
printf("\nReturning to Main Menu...\n");
break;

default:
printf("\nInvalid choice. Please enter 1, 2, 3 or 4.\n");
}

} while (choice != 4);
}

#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100

typedef struct {
int supplierID;
char name[50];
char email[50];
char telephone[20];
char town[50];
}supplier;

/*Supplier Manangement functions*/
void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);
void supplierMenu(void);

#endif
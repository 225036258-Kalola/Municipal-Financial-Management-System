#include <stdio.h>
#include <stdlib.h>
#include "integration.h"
#include "validation.h"
#include "string_utils.h"
#include "budget.h"
#include "employees.h"
#include "suppliers.h"
void addAsset(void);
void displayAssets(void);
void searchAsset(void);
#include "reports.h"


int globalEmployeeCount = 0;
int globalBudgetCount = 0;
int globalSupplierCount = 0;
int globalAssetCount = 0;

void displayMainMenu(void) {
    printf("\n========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM \n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("========================================\n");
}

void runIntegrationLoop(void) {
    int choice = 0;

    while (choice != 6) {
        displayMainMenu();
        choice = getValidInt("Enter choice (1-6): ", 1, 6);

        switch (choice) {
            case 1: integrateEmployeeModule(); break;
            case 2: integrateBudgetModule(); break;
            case 3: integrateSupplierModule(); break;
            case 4: integrateAssetModule(); break;
            case 5: integrateReportsModule(); break;
            case 6: printf("\nExiting System. Submission build complete.\n"); break;
            default: printf("\n[ERROR] Invalid choice.\n"); break;
        }
    }
}

void integrateEmployeeModule(void)
{
    int choice;

    do
    {
        printf("\n--- Employee Management ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Employee Report\n");
        printf("5. Back\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                employeeReport();
                break;

            case 5:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);

}


void integrateBudgetModule(void)
{
    budgetMenu();
}
void integrateSupplierModule(void)
{
    int choice;

    do
    {
        printf("\n--- Supplier Management ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back\n");
        printf("Enter choice: ");

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
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);
}

void integrateAssetModule(void)
{
    int choice;

    do
    {
        printf("\n--- Asset Management ---\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Back\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addAsset();
                break;

            case 2:
                displayAssets();
                break;

            case 3:
                searchAsset();
                break;

            case 4:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);
}


void integrateReportsModule(void)
{
    displayReportsMenu();
}
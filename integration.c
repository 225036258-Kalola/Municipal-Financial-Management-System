#include <stdio.h>
#include <stdlib.h>
#include "integration.h"
#include "validation.h"
#include "string_utils.h"

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

void integrateEmployeeModule(void) {
    printf("\n--- [Module 1] Employee Management ---\n");
    printf("1. Add Employee\n2. Back\n");
    int subChoice = getValidInt("Select option (1-2): ", 1, 2);
    if (subChoice == 1) {
        char name[50];
        getValidString("Enter Name: ", name, sizeof(name), false);
        double salary = getValidDouble("Enter Basic Salary (N$): ", 0.0, 1000000.0);
        globalEmployeeCount++;
        printf("[SUCCESS] Added %s with salary N$%.2f.\n", name, salary);
    }
}

void integrateBudgetModule(void) {
    printf("\n--- [Module 2] Budget Management ---\n");
    printf("1. Set Budget\n2. Back\n");
    int subChoice = getValidInt("Select option (1-2): ", 1, 2);
    if (subChoice == 1) {
        char dept[50];
        getValidString("Enter Department: ", dept, sizeof(dept), false);
        double budget = getValidDouble("Enter Budget (N$): ", 0.0, 50000000.0);
        globalBudgetCount++;
        printf("[SUCCESS] Budget assigned to %s: N$%.2f.\n", dept, budget);
    }
}

void integrateSupplierModule(void) {
    printf("\n--- [Module 3] Supplier Management ---\n");
    printf("1. Search Supplier\n2. Back\n");
    int subChoice = getValidInt("Select option (1-2): ", 1, 2);
    if (subChoice == 1) {
        char query[50], output[100];
        getValidString("Enter Search Term: ", query, sizeof(query), false);
        buildSearchQuery("SUPPLIER_SEARCH_", query, output, sizeof(output));
        printf("[SEARCH EXECUTION] Built string: %s\n", output);
        globalSupplierCount++;
    }
}

void integrateAssetModule(void) {
    printf("\n--- [Module 4] Asset Management ---\n");
    printf("1. Add Asset\n2. Back\n");
    int subChoice = getValidInt("Select option (1-2): ", 1, 2);
    if (subChoice == 1) {
        char asset[50];
        getValidString("Enter Asset Name: ", asset, sizeof(asset), false);
        double val = getValidDouble("Value (N$): ", 0.0, 10000000.0);
        globalAssetCount++;
        printf("[SUCCESS] Registered %s (N$%.2f).\n", asset, val);
    }
}

void integrateReportsModule(void) {
    printf("\n========================================\n");
    printf("           SYSTEM METRICS               \n");
    printf("========================================\n");
    printf("Employees Processed : %d\n", globalEmployeeCount);
    printf("Budgets Tracked     : %d\n", globalBudgetCount);
    printf("Suppliers Queried   : %d\n", globalSupplierCount);
    printf("Assets Cataloged    : %d\n", globalAssetCount);
    printf("========================================\n");
}
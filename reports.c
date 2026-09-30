#include <stdio.h>
#include <string.h>
#include "mfms.h"
#include "reports.h"

/* ---------- helpers ---------- */

static void printLine(void) {
    printf("--------------------------------------------------\n");
}

static double grossSalary(const Employee *e) {
    return e->basicSalary + e->housingAllowance + e->transportAllowance;
}

/* ---------- sub-menu ---------- */

void displayReportsMenu(void) {
    int choice;

    do {
        printf("\n===== REPORTS =====\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Assets by Department\n");
        printf("6. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');   /* clear bad input */
            choice = -1;
        }

        switch (choice) {
            case 1: generateEmployeeReport();     break;
            case 2: generateBudgetReport();       break;
            case 3: generateSupplierReport();     break;
            case 4: generateAssetReport();        break;
            case 5: generateAssetsByDepartment(); break;
            case 6: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);
}

/* ---------- 1. EMPLOYEE REPORT ---------- */

void generateEmployeeReport(void) {
    if (employeeCount == 0) {
        printf("\nNo employees registered.\n");
        return;
    }

    double total    = 0.0;
    double highest  = grossSalary(&employees[0]);
    double lowest   = grossSalary(&employees[0]);
    int    highIdx  = 0, lowIdx = 0;

    for (int i = 0; i < employeeCount; i++) {
        double g = grossSalary(&employees[i]);
        total += g;

        if (g > highest) { highest = g; highIdx = i; }
        if (g < lowest)  { lowest  = g; lowIdx  = i; }
    }

    printLine();
    printf("               EMPLOYEE REPORT\n");
    printLine();
    printf("Total Employees : %d\n", employeeCount);
    printf("Average Salary  : N$%.2f\n", total / employeeCount);
    printf("Highest Salary  : N$%.2f  (%s)\n", highest, employees[highIdx].name);
    printf("Lowest Salary   : N$%.2f  (%s)\n", lowest,  employees[lowIdx].name);
    printLine();
}

/* ---------- 2. BUDGET REPORT ---------- */

void generateBudgetReport(void) {
    if (departmentCount == 0) {
        printf("\nNo departmental budgets captured.\n");
        return;
    }

    double totalAllocated = 0.0;
    double totalSpent     = 0.0;

    for (int i = 0; i < departmentCount; i++) {
        totalAllocated += budgets[i].allocatedBudget;
        totalSpent     += budgets[i].expenditure;
    }

    printLine();
    printf("                BUDGET REPORT\n");
    printLine();
    printf("Total Allocated  : N$%.2f\n", totalAllocated);
    printf("Total Expenditure: N$%.2f\n", totalSpent);
    printf("Remaining Budget : N$%.2f\n", totalAllocated - totalSpent);

    printf("\nDepartments exceeding budget:\n");
    int found = 0;
    for (int i = 0; i < departmentCount; i++) {
        if (budgets[i].expenditure > budgets[i].allocatedBudget) {
            printf("  - %-20s over by N$%.2f\n",
                   budgets[i].department,
                   budgets[i].expenditure - budgets[i].allocatedBudget);
            found = 1;
        }
    }
    if (!found) printf("  None - all departments within budget.\n");
    printLine();
}

/* ---------- 3. SUPPLIER REPORT ---------- */

void generateSupplierReport(void) {
    if (supplierCount == 0) {
        printf("\nNo suppliers registered.\n");
        return;
    }

    printLine();
    printf("                SUPPLIER REPORT\n");
    printLine();
    printf("%-5s %-20s %-25s %-15s %-15s\n",
           "ID", "Name", "Email", "Telephone", "Town");
    printLine();

    for (int i = 0; i < supplierCount; i++) {
        printf("%-5d %-20s %-25s %-15s %-15s\n",
               suppliers[i].id,
               suppliers[i].name,
               suppliers[i].email,
               suppliers[i].telephone,
               suppliers[i].town);
    }
    printLine();
    printf("Total suppliers: %d\n", supplierCount);
}

/* ---------- 4. ASSET REPORT ---------- */

void generateAssetReport(void) {
    if (assetCount == 0) {
        printf("\nNo assets registered.\n");
        return;
    }

    double totalValue = 0.0;

    printLine();
    printf("                  ASSET REPORT\n");
    printLine();
    printf("%-5s %-20s %-15s %-12s %-15s %-12s\n",
           "ID", "Name", "Type", "Value", "Department", "Condition");
    printLine();

    for (int i = 0; i < assetCount; i++) {
        printf("%-5d %-20s %-15s N$%-10.2f %-15s %-12s\n",
               assets[i].id,
               assets[i].name,
               assets[i].type,
               assets[i].purchaseValue,
               assets[i].department,
               assets[i].condition);
        totalValue += assets[i].purchaseValue;
    }
    printLine();
    printf("Total assets : %d\n", assetCount);
    printf("Total value  : N$%.2f\n", totalValue);
}

/* ---------- 5. ASSETS BY DEPARTMENT (uses strcmp) ---------- */

void generateAssetsByDepartment(void) {
    if (assetCount == 0) {
        printf("\nNo assets registered.\n");
        return;
    }

    char target[NAME_LEN];
    printf("Enter department name: ");
    scanf(" %49[^\n]", target);

    int    found    = 0;
    double subtotal = 0.0;

    printLine();
    printf("   ASSETS IN DEPARTMENT: %s\n", target);
    printLine();
    printf("%-5s %-20s %-15s %-12s %-12s\n",
           "ID", "Name", "Type", "Value", "Condition");
    printLine();

    for (int i = 0; i < assetCount; i++) {
        if (strcmp(assets[i].department, target) == 0) {
            printf("%-5d %-20s %-15s N$%-10.2f %-12s\n",
                   assets[i].id,
                   assets[i].name,
                   assets[i].type,
                   assets[i].purchaseValue,
                   assets[i].condition);
            subtotal += assets[i].purchaseValue;
            found = 1;
        }
    }

    if (!found) {
        printf("No assets found for that department.\n");
    } else {
        printLine();
        printf("Subtotal for %s: N$%.2f\n", target, subtotal);
    }
}
#include <stdio.h>
#include <string.h>
#include "employees.h"

// Clear input buffer helper function
static void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\0' && c != EOF);
}

// Helper function to handle string inputs safely
static void readString(char *buffer, int size, const char *prompt) {
    do {
        printf("%s", prompt);
        if (fgets(buffer, size, stdin) != NULL) {
            // Remove newline character if present
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
            }
        }
        if (strlen(buffer) == 0) {
            printf("Error: Input cannot be empty. Please try again.\n");
        }
    } while (strlen(buffer) == 0);
}

// Helper function for non-negative float/double inputs
static double readPositiveDouble(const char *prompt) {
    double value;
    int status;
    do {
        printf("%s", prompt);
        status = scanf("%lf", &value);
        if (status != 1 || value < 0) {
            printf("Error: Please enter a valid non-negative number.\n");
            clearBuffer();
        }
    } while (status != 1 || value < 0);
    clearBuffer();
    return value;
}

// Calculates salary components for an employee
void calculateSalary(Employee *emp) {
    emp->gross_salary = emp->basic_salary + emp->housing_allowance + emp->transport_allowance;
}

// Adds a new employee with full validation
void addEmployee(Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\n[ERROR] Employee database is full! Cannot add more employees.\n");
        return;
    }

    Employee newEmp;
    printf("\n--- ADD NEW EMPLOYEE ---\n");

    // Auto-generate or set unique ID based on count
    newEmp.id = *count + 101;
    printf("Assigned Employee ID: %d\n", newEmp.id);

    readString(newEmp.name, NAME_LEN, "Enter Name: ");
    readString(newEmp.department, DEPT_LEN, "Enter Department: ");

    newEmp.basic_salary = readPositiveDouble("Enter Basic Salary (N$): ");
    newEmp.housing_allowance = readPositiveDouble("Enter Housing Allowance (N$): ");
    newEmp.transport_allowance = readPositiveDouble("Enter Transport Allowance (N$): ");

    // Perform salary calculation
    calculateSalary(&newEmp);

    // Save to array
    employees[*count] = newEmp;
    (*count)++;

    printf("\n[SUCCESS] Employee successfully added!\n");
}

// Displays individual employee details
void displaySingleEmployee(const Employee *emp) {
    printf("| %-5d | %-20s | %-15s | N$%-10.2f | N$%-10.2f | N$%-10.2f | N$%-10.2f |\n",
           emp->id,
           emp->name,
           emp->department,
           emp->basic_salary,
           emp->housing_allowance,
           emp->transport_allowance,
           emp->gross_salary);
}

// Displays all stored employees
void displayEmployees(const Employee employees[], int count) {
    if (count == 0) {
        printf("\nNo employee records found in system.\n");
        return;
    }

    printf("\n====================================================================================================\n");
    printf("| %-5s | %-20s | %-15s | %-12s | %-12s | %-12s | %-12s |\n",
           "ID", "Name", "Department", "Basic (N$)", "House (N$)", "Trans (N$)", "Gross (N$)");
    printf("====================================================================================================\n");

    for (int i = 0; i < count; i++) {
        displaySingleEmployee(&employees[i]);
    }
    printf("====================================================================================================\n");
    printf("Total Employees: %d\n", count);
}

// Searches for an employee by Name (using strcmp/strstr) or ID
void searchEmployee(const Employee employees[], int count) {
    if (count == 0) {
        printf("\nNo employee records available to search.\n");
        return;
    }

    int choice;
    printf("\n--- SEARCH EMPLOYEE ---\n");
    printf("1. Search by Employee ID\n");
    printf("2. Search by Employee Name\n");
    printf("Enter choice: ");
    
    if (scanf("%d", &choice) != 1) {
        clearBuffer();
        printf("Invalid choice.\n");
        return;
    }
    clearBuffer();

    if (choice == 1) {
        int searchId;
        printf("Enter Employee ID to search: ");
        if (scanf("%d", &searchId) != 1) {
            clearBuffer();
            printf("Invalid ID format.\n");
            return;
        }
        clearBuffer();

        for (int i = 0; i < count; i++) {
            if (employees[i].id == searchId) {
                printf("\nMatch Found:\n");
                printf("====================================================================================================\n");
                printf("| %-5s | %-20s | %-15s | %-12s | %-12s | %-12s | %-12s |\n",
                       "ID", "Name", "Department", "Basic (N$)", "House (N$)", "Trans (N$)", "Gross (N$)");
                printf("====================================================================================================\n");
                displaySingleEmployee(&employees[i]);
                printf("====================================================================================================\n");
                return;
            }
        }
        printf("\nNo employee found with ID: %d\n", searchId);

    } else if (choice == 2) {
        char searchName[NAME_LEN];
        readString(searchName, NAME_LEN, "Enter Employee Name to search: ");

        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(employees[i].name, searchName) == 0) {
                if (!found) {
                    printf("\nMatch Found:\n");
                    printf("====================================================================================================\n");
                    printf("| %-5s | %-20s | %-15s | %-12s | %-12s | %-12s | %-12s |\n",
                           "ID", "Name", "Department", "Basic (N$)", "House (N$)", "Trans (N$)", "Gross (N$)");
                    printf("====================================================================================================\n");
                }
                displaySingleEmployee(&employees[i]);
                found = 1;
            }
        }

        if (found) {
            printf("====================================================================================================\n");
        } else {
            printf("\nNo employee found matching name: \"%s\"\n", searchName);
        }
    } else {
        printf("\nInvalid search selection.\n");
    }
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mfms.h"
#include "employees.h"

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

int isEmptyName(char *str)
{
    if (strlen(str) == 0)
        return 1;

    for (int i = 0; i < strlen(str); i++)
    {
        if (!isspace((unsigned char)str[i]))
            return 0;
    }

    return 1;
}

void addEmployee()
{
    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("Employee list is full!\n");
        return;
    }

    Employee e;

    printf("Enter ID: ");
    scanf("%d", &e.id);

    if (e.id <= 0)
    {
        printf("ID must be positive!\n");
        return;
    }

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == e.id)
        {
            printf("ID already exists!\n");
            return;
        }
    }

    getchar();

    printf("Enter Name: ");
    fgets(e.name, NAME_LEN, stdin);
    e.name[strcspn(e.name, "\n")] = '\0';

    if (isEmptyName(e.name))
    {
        printf("Empty name is not allowed!\n");
        return;
    }

    printf("Enter Department: ");
    fgets(e.department, NAME_LEN, stdin);
    e.department[strcspn(e.department, "\n")] = '\0';

    printf("Enter Basic Salary: ");
    scanf("%lf", &e.basicSalary);

    if (e.basicSalary < 0)
    {
        printf("Salary cannot be negative!\n");
        return;
    }

    printf("Enter Housing Allowance: ");
    scanf("%lf", &e.housingAllowance);

    printf("Enter Transport Allowance: ");
    scanf("%lf", &e.transportAllowance);

    employees[employeeCount] = e;
    employeeCount++;

    printf("Employee %s added successfully!\n", e.name);
}

void displayEmployees()
{
    if (employeeCount == 0)
    {
        printf("No employees found.\n");
        return;
    }

    for (int i = 0; i < employeeCount; i++)
    {
        double total = calculateSalary(
            employees[i].basicSalary,
            employees[i].housingAllowance,
            employees[i].transportAllowance
        );

        printf("\nID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Department: %s\n", employees[i].department);
        printf("Basic Salary: N$%.2f\n", employees[i].basicSalary);
        printf("Housing Allowance: N$%.2f\n", employees[i].housingAllowance);
        printf("Transport Allowance: N$%.2f\n", employees[i].transportAllowance);
        printf("Total Salary: N$%.2f\n", total);
    }
}

void searchEmployee()
{
    char query[NAME_LEN];

    getchar();

    printf("Enter Name to search: ");
    fgets(query, NAME_LEN, stdin);
    query[strcspn(query, "\n")] = '\0';

    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(employees[i].name, query) == 0)
        {
            printf("\nEmployee Found!\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            return;
        }
    }

    printf("Employee not found.\n");
}

void employeeReport()
{
    if (employeeCount == 0)
    {
        printf("No employee data available.\n");
        return;
    }

    double total = 0;

    for (int i = 0; i < employeeCount; i++)
    {
        total += calculateSalary(
            employees[i].basicSalary,
            employees[i].housingAllowance,
            employees[i].transportAllowance
        );
    }

    printf("\n========== EMPLOYEE REPORT ==========\n");
    printf("Number of Employees: %d\n", employeeCount);
    printf("Total Salary Cost: N$%.2f\n", total);
    printf("Average Salary: N$%.2f\n", total / employeeCount);
}

#include <stdio.h>
#include <string.h>
#include "mfms.h"
#include "budget.h"


Department budgets[MAX_DEPARTMENTS];
int departmentCount = 0;


static int findDepartment(char searchName[])
{
    int i;

    for (i = 0; i < departmentCount; i++)
    {
        if (strcmp(budgets[i].department, searchName) == 0)
        {
            return i;
        }
    }
    return -1;
}

void addDepartment(void)
{
    char newName[NAME_LEN];
    double budget;

    if (departmentCount >= MAX_DEPARTMENTS)
    {
        printf("The department list is full.\n");
        return;
    }

    printf("Enter the department name: ");
    fgets(newName, NAME_LEN, stdin);
    newName[strlen(newName) - 1] = '\0';

    if (strlen(newName) == 0)
    {
        printf("The department name cannot be empty.\n");
        return;
    }

    if (findDepartment(newName) != -1)
    {
        printf("The department already exists.\n");
        return;
    }

    printf("Enter the allocated budget: ");
    scanf("%lf", &budget);

    while (budget < 0)
    {
        printf("The budget cannot be negative please Try again: ");
        scanf("%lf", &budget);
    }
    getchar();

    strcpy(budgets[departmentCount].department, newName);
    budgets[departmentCount].allocatedBudget = budget;
    budgets[departmentCount].expenditure = 0;
    departmentCount++;
    printf("Department is saved.\n");
}

void enterMoneySpent(void)
{
    char searchName[NAME_LEN];
    double amount;
    int position;

    printf("Enter thedepartment name: ");
    fgets(searchName, NAME_LEN, stdin);
    searchName[strlen(searchName) - 1] = '\0';

    position = findDepartment(searchName);

    if (position == -1)
    {
        printf("Department is not found.\n");
        return;
    }

    printf("Enter the money spent: ");
    scanf("%lf", &amount);

    while (amount < 0)
    {
        printf("The money spent cannot be negative. Try again: ");
        scanf("%lf", &amount);
    }
    getchar();

    budgets[position].expenditure = budgets[position].expenditure + amount;
    printf("The money spent is saved. Total spent by %s: N$%.2f\n",
           budgets[position].department, budgets[position].expenditure);
}


double calculateRemaining(int position)
{
    return budgets[position].allocatedBudget - budgets[position].expenditure;
}

void checkBudget(void)
{
    char searchName[NAME_LEN];
    int position;
    double remaining;

    printf("Enter the department name: ");
    fgets(searchName, NAME_LEN, stdin);
    searchName[strlen(searchName) - 1] = '\0';

    position = findDepartment(searchName);

    if (position == -1)
    {
        printf("The department is not found.\n");
        return;
    }

    remaining = calculateRemaining(position);

    printf("Department: %s\n", budgets[position].department);
    printf("Allocated Budget: N$%.2f\n", budgets[position].allocatedBudget);
    printf("Money Spent: N$%.2f\n", budgets[position].expenditure);
    printf("Remaining Budget: N$%.2f\n", remaining);

    if (remaining >= 0)
    {
        printf("Status: The budget is within limits\n");
    }
    else
    {
        printf("Status: The budget has been exceeded\n");
    }
}

void displayBudgets(void)
{
    int i;
    double remaining;

    if (departmentCount == 0)
    {
        printf("No are departments entered yet.\n");
        return;
    }

    printf("\n%-20s %-15s %-15s %-15s %s\n",
           "Department", "Allocated", "Money Spent", "Remaining", "Status");

    for (i = 0; i < departmentCount; i++)
    {
        remaining = calculateRemaining(i);

        printf("%-20s %-15.2f %-15.2f %-15.2f ",
               budgets[i].department, budgets[i].allocatedBudget,
               budgets[i].expenditure, remaining);

        if (remaining >= 0)
        {
            printf("The budget is within limits\n");
        }
        else
        {
            printf("The budget has been exceeded\n");
        }
    }
}

void showOverBudget(void)
{
    int i;
    int overCount = 0;

    printf("\n The departments that exceeded their budget is:\n");

    for (i = 0; i < departmentCount; i++)
    {
        if (budgets[i].expenditure > budgets[i].allocatedBudget)
        {
            printf("- %s (over by N$%.2f)\n", budgets[i].department,
                   budgets[i].expenditure - budgets[i].allocatedBudget);
            overCount++;
        }
    }

    if (overCount == 0)
    {
        printf(" All departments are within budget.\n");
    }
}

static void displayBudgetMenu(void)
{
    printf("\n<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>\n");
    printf("BUDGET MANAGEMENT\n");
    printf("<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>\n");
    printf("Departments stored: %d\n", departmentCount);
    printf("1. Enter department budget\n");
    printf("2. Enter money spent\n");
    printf("3. Check one department\n");
    printf("4. Display all budgets\n");
    printf("5. Show departments over budget\n");
    printf("6. Back to main menu\n");
    printf("Enter your choice: ");
}


void budgetMenu(void)
{
    int choice;
    int result;

    do
    {
        displayBudgetMenu();
        result = scanf("%d", &choice);
        while (getchar() != '\n');

        if (result != 1)
        {
            choice = 0;
        }

        switch (choice)
        {
            case 1: addDepartment(); break;
            case 2: enterMoneySpent(); break;
            case 3: checkBudget(); break;
            case 4: displayBudgets(); break;
            case 5: showOverBudget(); break;
            case 6: break;
            default: printf("Invalid choice. Please enter a number from 1 to 6.\n");
        }
    } while (choice != 6);
}
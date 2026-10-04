#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100
#define NAME_LEN 50
#define DEPT_LEN 30

typedef struct {
    int id;
    char name[NAME_LEN];
    char department[DEPT_LEN];
    double basic_salary;
    double housing_allowance;
    double transport_allowance;
    double gross_salary;
} Employee;

// Function Declarations
void initEmployees(Employee employees[], int *count);
void addEmployee(Employee employees[], int *count);
void displayEmployees(const Employee employees[], int count);
void searchEmployee(const Employee employees[], int count);
void calculateSalary(Employee *emp);
void displaySingleEmployee(const Employee *emp);

#endif // EMPLOYEES_H

#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#define MAX_EMP 100
struct Employee {
    int id;
    char name[50];
    char department[30];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
    char email[50];
};
void addEmployee();
void displayEmployees();
void searchEmployee();
void displaySalaryInfo();
float calculateSalary(float basic, float housing, float transport);
int isEmptyName(char *str);
extern struct Employee employees[MAX_EMP];
extern int empCount;
#endif

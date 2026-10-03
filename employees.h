#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "mfms.h"

void addEmployee();
void displayEmployees();
void searchEmployee();
void displaySalaryInfo();

float calculateSalary(float basic, float housing, float transport);

int isEmptyName(char *str);

extern int empCount;

#endif
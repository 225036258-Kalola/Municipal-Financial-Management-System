/*
 *  TEST main.c  —  Reports module demo / dummy data
 *  ------------------------------------------------
 *  TEMPORARY file. Replace with the group's real main.c
 *  before final submission. Kept here so the Reports
 *  module can be compiled and demonstrated in isolation.
 */

#include <stdio.h>
#include <string.h>
#include "mfms.h"
#include "reports.h"

/* ---- Global storage (owned by each module in the real system) ---- */
Employee   employees[MAX_EMPLOYEES];
int        employeeCount = 0;

Department budgets[MAX_DEPARTMENTS];
int        departmentCount = 0;

Supplier   suppliers[MAX_SUPPLIERS];
int        supplierCount = 0;

Asset      assets[MAX_ASSETS];
int        assetCount = 0;

/* ---- Dummy data seed ---- */
static void seedDummyData(void) {
    /* Employees */
    employees[0] = (Employee){ 101, "John Kambwa",     "Finance",    15000, 3000, 1500 };
    employees[1] = (Employee){ 102, "Maria Nghidinwa", "HR",         12000, 2500, 1200 };
    employees[2] = (Employee){ 103, "Peter Shikongo",  "IT",         18000, 3500, 1800 };
    employees[3] = (Employee){ 104, "Anna Kapala",     "Finance",     9500, 2000,  900 };
    employees[4] = (Employee){ 105, "David Uusiku",    "Engineering",14500, 3000, 1400 };
    employeeCount = 5;

    /* Departments / budgets */
    budgets[0] = (Department){ "Finance",     500000, 420000 };
    budgets[1] = (Department){ "HR",          250000, 180000 };
    budgets[2] = (Department){ "IT",          300000, 350000 };  /* over budget */
    budgets[3] = (Department){ "Engineering", 400000, 250000 };
    departmentCount = 4;

    /* Suppliers */
    suppliers[0] = (Supplier){ 201, "Namibia Office Supplies", "sales@namsupplies.na",  "0611234567", "Windhoek" };
    suppliers[1] = (Supplier){ 202, "Coastal IT Solutions",    "info@coastit.na",       "0642223333", "Swakopmund" };
    suppliers[2] = (Supplier){ 203, "Northern Builders CC",    "contact@nbcc.na",       "0654445555", "Ondangwa" };
    supplierCount = 3;

    /* Assets */
    assets[0] = (Asset){ 301, "Toyota Hilux",  "Vehicle",   350000, "Engineering", "Good" };
    assets[1] = (Asset){ 302, "Dell Laptop",   "Computer",   15000, "IT",          "Excellent" };
    assets[2] = (Asset){ 303, "Office Desk",   "Furniture",   3500, "Finance",     "Fair" };
    assets[3] = (Asset){ 304, "Generator",     "Equipment",  45000, "Engineering", "Good" };
    assets[4] = (Asset){ 305, "HP Printer",    "Equipment",   8000, "HR",          "Good" };
    assetCount = 5;
}

/* ---- Main ---- */
int main(void) {
    seedDummyData();

    printf("\n==================================================\n");
    printf("  TEST MODE - Reports module with dummy data\n");
    printf("  (Not the real main.c - temporary for testing)\n");
    printf("==================================================\n");

    displayReportsMenu();

    printf("\nExiting test program.\n");
    return 0;
}
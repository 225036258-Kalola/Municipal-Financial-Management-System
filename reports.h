#ifndef REPORTS_H
#define REPORTS_H

/* Top-level reports sub-menu. Called from main.c option 5. */
void displayReportsMenu(void);

/* Individual reports */
void generateEmployeeReport(void);
void generateBudgetReport(void);
void generateSupplierReport(void);
void generateAssetReport(void);

/* Filter an asset report by department (uses strcmp) */
void generateAssetsByDepartment(void);

#endif
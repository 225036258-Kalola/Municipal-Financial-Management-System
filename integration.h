#ifndef INTEGRATION_H
#define INTEGRATION_H

extern int globalEmployeeCount;
extern int globalBudgetCount;
extern int globalSupplierCount;
extern int globalAssetCount;

void displayMainMenu(void);
void runIntegrationLoop(void);

void integrateEmployeeModule(void);
void integrateBudgetModule(void);
void integrateSupplierModule(void);
void integrateAssetModule(void);
void integrateReportsModule(void);

#endif 
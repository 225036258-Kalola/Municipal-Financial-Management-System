#ifndef MFMS_H
#define MFMS_H

/* ---- Limits ---- */
#define MAX_EMPLOYEES   100
#define MAX_DEPARTMENTS 20
#define MAX_SUPPLIERS   100
#define MAX_ASSETS      200

#define NAME_LEN 50
#define TEXT_LEN 100

/* ---- Structs ---- */

typedef struct {
    int    id;
    char   name[NAME_LEN];
    char   department[NAME_LEN];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;
} Employee;

typedef struct {
    char   department[NAME_LEN];
    double allocatedBudget;
    double expenditure;
} Department;

typedef struct {
    int  id;
    char name[NAME_LEN];
    char email[TEXT_LEN];
    char telephone[20];
    char town[NAME_LEN];
} Supplier;

typedef struct {
    int    id;
    char   name[NAME_LEN];
    char   type[NAME_LEN];
    double purchaseValue;
    char   department[NAME_LEN];
    char   condition[NAME_LEN];
} Asset;

/* ---- Globals owned by each module (defined in their .c file) ---- */
extern Employee   employees[MAX_EMPLOYEES];
extern int        employeeCount;

extern Department budgets[MAX_DEPARTMENTS];
extern int        departmentCount;

extern Supplier   suppliers[MAX_SUPPLIERS];
extern int        supplierCount;

extern Asset      assets[MAX_ASSETS];
extern int        assetCount;

#endif
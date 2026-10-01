#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_EMP 100

struct Employee {
    int id;
    char name[50];
    char department[30];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
};

struct Employee employees[MAX_EMP];
int empCount = 0;

float calculateSalary(float basic, float housing, float transport){
    return basic + housing + transport;
}

int isEmptyName(char *str){
    if(strlen(str)==0) return 1;
    for(int i=0;i<strlen(str);i++){
        if(!isspace(str[i])) return 0;
    }
    return 1;
}

void addEmployee(){
    if(empCount>=MAX_EMP){ printf("Full!\n"); return; }
    struct Employee e;
    printf("Enter ID: ");
    scanf("%d",&e.id);
    if(e.id<=0){ printf("ID cannot be negative!\n"); return; }
    for(int i=0;i<empCount;i++) if(employees[i].id==e.id){ printf("ID exists!\n"); return; }

    printf("Enter Name: ");
    getchar();
    fgets(e.name,50,stdin);
    e.name[strcspn(e.name,"\n")]='\0';
    if(isEmptyName(e.name)){ printf("Empty name not allowed!\n"); return; }

    printf("Enter Department: ");
    fgets(e.department,30,stdin);
    e.department[strcspn(e.department,"\n")]='\0';

    printf("Enter Basic Salary: ");
    scanf("%f",&e.basicSalary);
    if(e.basicSalary<0){ printf("Negative salary not accepted!\n"); return; }

    printf("Enter Housing: ");
    scanf("%f",&e.housingAllowance);
    printf("Enter Transport: ");
    scanf("%f",&e.transportAllowance);

    employees[empCount]=e;
    empCount++;
    printf("Employee %s added! Total %d\n", e.name, empCount);
}

void displayEmployees(){
    if(empCount==0){ printf("No employees.\n"); return; }
    for(int i=0;i<empCount;i++){
        float total=calculateSalary(employees[i].basicSalary, employees[i].housingAllowance, employees[i].transportAllowance);
        printf("ID:%d Name:%s Dept:%s Total:N$%.2f\n", employees[i].id, employees[i].name, employees[i].department, total);
    }
}

void searchEmployee(){
    char query[50];
    printf("Enter Name to search: ");
    getchar();
    fgets(query,50,stdin);
    query[strcspn(query,"\n")]='\0';
    for(int i=0;i<empCount;i++){
        if(strcmp(employees[i].name,query)==0){
            printf("FOUND ID:%d Name:%s Dept:%s\n", employees[i].id, employees[i].name, employees[i].department);
            return;
        }
    }
    printf("Not found!\n");
}

void employeeReport(){
    if(empCount==0){ printf("No data.\n"); return; }
    float sum=0;
    for(int i=0;i<empCount;i++) sum+=calculateSalary(employees[i].basicSalary, employees[i].housingAllowance, employees[i].transportAllowance);
    printf("Total:%d Average:N$%.2f\n", empCount, sum/empCount);
}

int main(){
    int ch;
    do{
        printf("\n1.Add 2.Display 3.Search 4.Report 5.Exit\nChoice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: employeeReport(); break;
            case 5: printf("Bye\n"); break;
            default: printf("Invalid choice!\n");
        }
    }while(ch!=5);
    return 0;
}

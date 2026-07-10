#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    float basic_salary;
    float allowances;
    float deductions;
    float net_salary;
};

void calculateSalary(struct Employee *emp) {
    emp->net_salary = emp->basic_salary + emp->allowances - emp->deductions;
}

void addEmployee(struct Employee empList[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\nSystem full! Cannot add more employees.\n");
        return;
    }
    
    struct Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    
    for (int i = 0; i < *count; i++) {
        if (empList[i].id == emp.id) {
            printf("Error: Employee ID already exists!\n");
            return;
        }
    }
    
    printf("Enter Name: ");
    scanf(" %[^\n]s", emp.name);
    printf("Enter Basic Salary: ");
    scanf("%f", &emp.basic_salary);
    printf("Enter Allowances: ");
    scanf("%f", &emp.allowances);
    printf("Enter Deductions: ");
    scanf("%f", &emp.deductions);
    
    calculateSalary(&emp);
    
    empList[*count] = emp;
    (*count)++;
    printf("Employee added successfully!\n");
}

void displayEmployees(struct Employee empList[], int count) {
    if (count == 0) {
        printf("\nNo employee records found.\n");
        return;
    }
    
    printf("\n========================================================================\n");
    printf("%-5s %-20s %-12s %-12s %-12s %-12s\n", "ID", "Name", "Basic", "Allowances", "Deductions", "Net Salary");
    printf("========================================================================\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-12.2f %-12.2f %-12.2f %-12.2f\n", 
               empList[i].id, empList[i].name, empList[i].basic_salary, 
               empList[i].allowances, empList[i].deductions, empList[i].net_salary);
    }
    printf("========================================================================\n");
}

void searchEmployee(struct Employee empList[], int count) {
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }
    
    int searchId, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);
    
    for (int i = 0; i < count; i++) {
        if (empList[i].id == searchId) {
            printf("\nRecord Found:\n");
            printf("ID: %d\nName: %s\nBasic: %.2f\nAllowances: %.2f\nDeductions: %.2f\nNet Salary: %.2f\n",
                   empList[i].id, empList[i].name, empList[i].basic_salary, 
                   empList[i].allowances, empList[i].deductions, empList[i].net_salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", searchId);
    }
}

void modifyEmployee(struct Employee empList[], int count) {
    if (count == 0) {
        printf("\nNo records available to modify.\n");
        return;
    }
    
    int modifyId, found = 0;
    printf("\nEnter Employee ID to modify: ");
    scanf("%d", &modifyId);
    
    for (int i = 0; i < count; i++) {
        if (empList[i].id == modifyId) {
            printf("\nCurrent Details:\nName: %s, Basic: %.2f\n", empList[i].name, empList[i].basic_salary);
            printf("\nEnter New Name: ");
            scanf(" %[^\n]s", empList[i].name);
            printf("Enter New Basic Salary: ");
            scanf("%f", &empList[i].basic_salary);
            printf("Enter New Allowances: ");
            scanf("%f", &empList[i].allowances);
            printf("Enter New Deductions: ");
            scanf("%f", &empList[i].deductions);
            
            calculateSalary(&empList[i]);
            printf("Record updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", modifyId);
    }
}

int main() {
    struct Employee empList[MAX_EMPLOYEES];
    int count = 0;
    int choice;
    
    while (1) {
        printf("\n--- SALARY MANAGEMENT SYSTEM ---\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Modify Employee Salary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEmployee(empList, &count);
                break;
            case 2:
                displayEmployees(empList, count);
                break;
            case 3:
                searchEmployee(empList, count);
                break;
            case 4:
                modifyEmployee(empList, count);
                break;
            case 5:
                printf("\nExiting system. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

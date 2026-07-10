#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    char designation[50];
    float salary;
};

struct Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("\nSystem is full. Cannot add more employees.\n");
        return;
    }
    
    struct Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);
    
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == emp.id) {
            printf("Error: Employee ID already exists.\n");
            return;
        }
    }
    
    printf("Enter Name: ");
    scanf(" %[^\n]s", emp.name);
    printf("Enter Designation: ");
    scanf(" %[^\n]s", emp.designation);
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);
    
    employees[employeeCount] = emp;
    employeeCount++;
    printf("Employee added successfully.\n");
}

void displayEmployees() {
    if (employeeCount == 0) {
        printf("\nNo records found.\n");
        return;
    }
    
    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%-10d %-20s %-20s %-10.2f\n", 
               employees[i].id, employees[i].name, employees[i].designation, employees[i].salary);
    }
}

void searchEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records available to search.\n");
        return;
    }
    
    int id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            printf("\nEmployee Found:\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Designation: %s\n", employees[i].designation);
            printf("Salary: %.2f\n", employees[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void updateEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records available to update.\n");
        return;
    }
    
    int id;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            printf("Enter New Name: ");
            scanf(" %[^\n]s", employees[i].name);
            printf("Enter New Designation: ");
            scanf(" %[^\n]s", employees[i].designation);
            printf("Enter New Salary: ");
            scanf("%f", &employees[i].salary);
            printf("Employee record updated successfully.\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void deleteEmployee() {
    if (employeeCount == 0) {
        printf("\nNo records available to delete.\n");
        return;
    }
    
    int id;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Employee deleted successfully.\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

int main() {
    int choice;
    
    while (1) {
        printf("\n*** Mini Employee Management System ***\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                updateEmployee();
                break;
            case 5:
                deleteEmployee();
                break;
            case 6:
                printf("\nExiting program. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

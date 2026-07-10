#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

struct Student {
    int rollNumber;
    char name[NAME_LEN];
    float marks;
};

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nSystem database is full.\n");
        return;
    }
    
    printf("\nEnter Roll Number: ");
    scanf("%d", &students[*count].rollNumber);
    getchar();
    
    printf("Enter Name: ");
    fgets(students[*count].name, NAME_LEN, stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0';
    
    printf("Enter Marks: ");
    scanf("%f", &students[*count].marks);
    
    (*count)++;
    printf("Record added successfully!\n");
}

void displayStudents(const struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }
    
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Name       : %s\n", students[i].name);
        printf("Marks      : %.2f\n", students[i].marks);
        printf("---------------------\n");
    }
}

void searchStudent(const struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }
    
    int roll;
    int found = 0;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);
    
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == roll) {
            printf("\nRecord Found:\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name       : %s\n", students[i].name);
            printf("Marks      : %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Student with Roll Number %d not found.\n", roll);
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;
    
    do {
        printf("\n*** Student Record System ***\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

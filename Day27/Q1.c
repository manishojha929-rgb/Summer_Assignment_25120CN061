#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int roll_no;
    char name[50];
    float gpa;
} Student;

void add_student(const char *filename) {
    FILE *file = fopen(filename, "ab");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    Student s;
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll_no);
    getchar();
    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';
    printf("Enter GPA: ");
    scanf("%f", &s.gpa);
    fwrite(&s, sizeof(Student), 1, file);
    fclose(file);
    printf("Record added successfully!\n");
}

void display_students(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("No records found!\n");
        return;
    }
    Student s;
    printf("\n--- Student Records ---\n");
    while (fread(&s, sizeof(Student), 1, file)) {
        printf("Roll No: %d | Name: %s | GPA: %.2f\n", s.roll_no, s.name, s.gpa);
    }
    fclose(file);
}

void search_student(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("No records found!\n");
        return;
    }
    int roll, found = 0;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);
    Student s;
    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.roll_no == roll) {
            printf("\nRecord Found:\n");
            printf("Roll No: %d\nName: %s\nGPA: %.2f\n", s.roll_no, s.name, s.gpa);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record not found!\n");
    }
    fclose(file);
}

void delete_student(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("No records found!\n");
        return;
    }
    FILE *temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }
    int roll, found = 0;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);
    Student s;
    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.roll_no == roll) {
            found = 1;
        } else {
            fwrite(&s, sizeof(Student), 1, temp);
        }
    }
    fclose(file);
    fclose(temp);
    if (found) {
        remove(filename);
        rename("temp.dat", filename);
        printf("Record deleted successfully!\n");
    } else {
        remove("temp.dat");
        printf("Record not found!\n");
    }
}

int main() {
    const char *filename = "students.dat";
    int choice;
    while (1) {
        printf("\n*** Student Record Management System ***\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_student(filename);
                break;
            case 2:
                display_students(filename);
                break;
            case 3:
                search_student(filename);
                break;
            case 4:
                delete_student(filename);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

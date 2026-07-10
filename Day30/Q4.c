#include <stdio.h>
#include <string.h>

#define MAX 5

struct Student
{
    int roll;
    char name[50];
    float marks;
};

struct Student s[MAX];

void inputStudents()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("\nEnter Roll Number: ");
        scanf("%d", &s[i].roll);

        printf("Enter Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }
}

void displayStudents()
{
    int i;
    printf("\nStudent Records\n");
    for (i = 0; i < MAX; i++)
    {
        printf("\nRoll Number: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nMarks: %.2f\n", s[i].marks);
    }
}

void searchStudent()
{
    int roll, i, found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for (i = 0; i < MAX; i++)
    {
        if (s[i].roll == roll)
        {
            printf("\nRecord Found");
            printf("\nRoll Number: %d", s[i].roll);
            printf("\nName: %s", s[i].name);
            printf("\nMarks: %.2f\n", s[i].marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nRecord Not Found\n");
}

void averageMarks()
{
    int i;
    float sum = 0;

    for (i = 0; i < MAX; i++)
        sum += s[i].marks;

    printf("\nAverage Marks = %.2f\n", sum / MAX);
}

int main()
{
    int choice;

    do
    {
        printf("\n===== Student Record Management System =====");
        printf("\n1. Input Student Details");
        printf("\n2. Display Student Details");
        printf("\n3. Search Student");
        printf("\n4. Average Marks");
        printf("\n5. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            inputStudents();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            averageMarks();
            break;
        case 5:
            printf("\nThank You!\n");
            break;
        default:
            printf("\nInvalid Choice\n");
        }

    } while (choice != 5);

    return 0;
}
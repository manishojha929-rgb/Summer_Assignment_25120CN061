#include <stdio.h>
#include <stdlib.h>

int main() {
    char name[50], course[50];
    int rollNo;
    float m1, m2, m3, m4, m5, total, percentage;
    
    printf("Enter Student Name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter Course Name: ");
    fgets(course, sizeof(course), stdin);
    printf("Enter Roll Number: ");
    scanf("%d", &rollNo);
    
    printf("Enter marks for 5 subjects (out of 100):\n");
    printf("Subject 1: ");
    scanf("%f", &m1);
    printf("Subject 2: ");
    scanf("%f", &m2);
    printf("Subject 3: ");
    scanf("%f", &m3);
    printf("Subject 4: ");
    scanf("%f", &m4);
    printf("Subject 5: ");
    scanf("%f", &m5);

    total = m1 + m2 + m3 + m4 + m5;
    percentage = (total / 500) * 100;

    system("cls||clear");

    printf("\n=============================================\n");
    printf("               STUDENT MARKSHEET             \n");
    printf("=============================================\n");
    printf("Roll Number : %d\n", rollNo);
    printf("Student Name: %s", name);
    printf("Course Name : %s", course);
    printf("---------------------------------------------\n");
    printf("Subject 1   : %.2f / 100\n", m1);
    printf("Subject 2   : %.2f / 100\n", m2);
    printf("Subject 3   : %.2f / 100\n", m3);
    printf("Subject 4   : %.2f / 100\n", m4);
    printf("Subject 5   : %.2f / 100\n", m5);
    printf("---------------------------------------------\n");
    printf("Total Marks : %.2f / 500\n", total);
    printf("Percentage  : %.2f%%\n", percentage);
    printf("Grade       : ");

    if (percentage >= 90) {
        printf("A\n");
    } else if (percentage >= 80) {
        printf("B\n");
    } else if (percentage >= 70) {
        printf("C\n");
    } else if (percentage >= 60) {
        printf("D\n");
    } else {
        printf("F\n");
    }
    
    printf("=============================================\n");

    return 0;
}

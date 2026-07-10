#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
    int is_issued;
};

void addBook() {
    FILE *fp = fopen("library_books.dat", "ab");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    struct Book b;
    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    getchar();
    printf("Enter Book Title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = 0;
    printf("Enter Author Name: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = 0;
    b.is_issued = 0;
    fwrite(&b, sizeof(struct Book), 1, fp);
    fclose(fp);
    printf("Book added successfully!\n");
}

void displayBooks() {
    FILE *fp = fopen("library_books.dat", "rb");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }
    struct Book b;
    printf("\n%-10s %-30s %-30s %-10s\n", "ID", "Title", "Author", "Status");
    printf("------------------------------------------------------------------------- \n");
    while (fread(&b, sizeof(struct Book), 1, fp)) {
        printf("%-10d %-30s %-30s %-10s\n", b.id, b.title, b.author, b.is_issued ? "Issued" : "Available");
    }
    fclose(fp);
}

void searchBook() {
    FILE *fp = fopen("library_books.dat", "rb");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }
    int id, found = 0;
    struct Book b;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);
    while (fread(&b, sizeof(struct Book), 1, fp)) {
        if (b.id == id) {
            printf("\nBook Found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n", b.id, b.title, b.author, b.is_issued ? "Issued" : "Available");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
    fclose(fp);
}

void issueBook() {
    FILE *fp = fopen("library_books.dat", "rb+");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }
    int id, found = 0;
    struct Book b;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    while (fread(&b, sizeof(struct Book), 1, fp)) {
        if (b.id == id) {
            found = 1;
            if (b.is_issued) {
                printf("Book is already issued.\n");
            } else {
                b.is_issued = 1;
                fseek(fp, -sizeof(struct Book), SEEK_CUR);
                fwrite(&b, sizeof(struct Book), 1, fp);
                printf("Book issued successfully!\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
    fclose(fp);
}

void returnBook() {
    FILE *fp = fopen("library_books.dat", "rb+");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }
    int id, found = 0;
    struct Book b;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    while (fread(&b, sizeof(struct Book), 1, fp)) {
        if (b.id == id) {
            found = 1;
            if (!b.is_issued) {
                printf("Book was not issued.\n");
            } else {
                b.is_issued = 0;
                fseek(fp, -sizeof(struct Book), SEEK_CUR);
                fwrite(&b, sizeof(struct Book), 1, fp);
                printf("Book returned successfully!\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
    fclose(fp);
}

int main() {
    int choice;
    while (1) {
        printf("\n*** Library Management System ***\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

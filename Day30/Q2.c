#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[50];
    int is_issued;
};

struct Book library[MAX_BOOKS];
int book_count = 0;

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("\nLibrary is full!\n");
        return;
    }
    struct Book b;
    printf("\nEnter Book ID: ");
    scanf("%d", &b.id);
    getchar();
    printf("Enter Title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = 0;
    printf("Enter Author: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = 0;
    b.is_issued = 0;
    library[book_count] = b;
    book_count++;
    printf("Book added successfully!\n");
}

void display_books() {
    if (book_count == 0) {
        printf("\nNo books in the library.\n");
        return;
    }
    printf("\n%-10s %-30s %-20s %-10s\n", "ID", "Title", "Author", "Status");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < book_count; i++) {
        printf("%-10d %-30s %-20s %-10s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].is_issued ? "Issued" : "Available");
    }
}

void search_book() {
    if (book_count == 0) {
        printf("\nNo books available to search.\n");
        return;
    }
    int id, found = 0;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            printf("\nBook Found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n", 
                   library[i].id, library[i].title, library[i].author, 
                   library[i].is_issued ? "Issued" : "Available");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nBook with ID %d not found.\n", id);
    }
}

void issue_book() {
    int id, found = 0;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            found = 1;
            if (library[i].is_issued) {
                printf("\nBook is already issued.\n");
            } else {
                library[i].is_issued = 1;
                printf("\nBook issued successfully!\n");
            }
            break;
        }
    }
    if (!found) {
        printf("\nBook with ID %d not found.\n", id);
    }
}

void return_book() {
    int id, found = 0;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            found = 1;
            if (!library[i].is_issued) {
                printf("\nBook was not issued.\n");
            } else {
                library[i].is_issued = 0;
                printf("\nBook returned successfully!\n");
            }
            break;
        }
    }
    if (!found) {
        printf("\nBook with ID %d not found.\n", id);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n=== MINI LIBRARY SYSTEM ===\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        switch (choice) {
            case 1: add_book(); break;
            case 2: display_books(); break;
            case 3: search_book(); break;
            case 4: issue_book(); break;
            case 5: return_book(); break;
            case 6: exit(0);
            default: printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void create(int arr[], int *n) {
    printf("Enter number of elements: ");
    scanf("%d", n);
    if (*n > MAX || *n < 0) {
        printf("Invalid size. Resetting to 0.\n");
        *n = 0;
        return;
    }
    printf("Enter %d elements: ", *n);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int arr[], int *n) {
    if (*n >= MAX) {
        printf("Array overflow.\n");
        return;
    }
    int elem, pos;
    printf("Enter element to insert: ");
    scanf("%d", &elem);
    printf("Enter position (1 to %d): ", *n + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > *n + 1) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = *n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = elem;
    (*n)++;
    printf("Element inserted successfully.\n");
}

void deleteElement(int arr[], int *n) {
    if (*n == 0) {
        printf("Array underflow. No elements to delete.\n");
        return;
    }
    int pos;
    printf("Enter position to delete (1 to %d): ", *n);
    scanf("%d", &pos);
    if (pos < 1 || pos > *n) {
        printf("Invalid position.\n");
        return;
    }
    printf("Deleted element: %d\n", arr[pos - 1]);
    for (int i = pos - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void search(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    int elem, found = -1;
    printf("Enter element to search: ");
    scanf("%d", &elem);
    for (int i = 0; i < n; i++) {
        if (arr[i] == elem) {
            found = i;
            break;
        }
    }
    if (found != -1) {
        printf("Element found at position %d (index %d).\n", found + 1, found);
    } else {
        printf("Element not found.\n");
    }
}

int main() {
    int arr[MAX];
    int n = 0;
    int choice;

    while (1) {
        printf("\n--- ARRAY OPERATIONS MENU ---\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Search Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create(arr, &n);
                break;
            case 2:
                display(arr, n);
                break;
            case 3:
                insert(arr, &n);
                break;
            case 4:
                deleteElement(arr, &n);
                break;
            case 5:
                search(arr, n);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

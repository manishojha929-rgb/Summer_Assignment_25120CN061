#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    int id;
    char name[50];
    int quantity;
    double price;
};

struct Inventory {
    struct Item items[MAX_ITEMS];
    int count;
};

void addItem(struct Inventory *inv) {
    if (inv->count >= MAX_ITEMS) {
        printf("\nInventory is full!\n");
        return;
    }
    struct Item newItem;
    printf("\nEnter Item ID: ");
    scanf("%d", &newItem.id);
    for (int i = 0; i < inv->count; i++) {
        if (inv->items[i].id == newItem.id) {
            printf("\nError: Item ID already exists!\n");
            return;
        }
    }
    printf("Enter Item Name: ");
    scanf(" %[^\n]s", newItem.name);
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter Price: ");
    scanf("%lf", &newItem.price);
    inv->items[inv->count] = newItem;
    inv->count++;
    printf("\nItem added successfully!\n");
}

void displayInventory(const struct Inventory *inv) {
    if (inv->count == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    printf("\n%-10s %-25s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < inv->count; i++) {
        printf("%-10d %-25s %-10d $%-9.2f\n", 
               inv->items[i].id, 
               inv->items[i].name, 
               inv->items[i].quantity, 
               inv->items[i].price);
    }
}

void updateStock(struct Inventory *inv) {
    int id, found = 0;
    printf("\nEnter Item ID to update stock: ");
    scanf("%d", &id);
    for (int i = 0; i < inv->count; i++) {
        if (inv->items[i].id == id) {
            printf("Current Quantity: %d\n", inv->items[i].quantity);
            printf("Enter New Quantity: ");
            scanf("%d", &inv->items[i].quantity);
            printf("\nStock updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nItem ID not found!\n");
    }
}

void searchItem(const struct Inventory *inv) {
    int id, found = 0;
    printf("\nEnter Item ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < inv->count; i++) {
        if (inv->items[i].id == id) {
            printf("\nItem Found:\n");
            printf("ID: %d\n", inv->items[i].id);
            printf("Name: %s\n", inv->items[i].name);
            printf("Quantity: %d\n", inv->items[i].quantity);
            printf("Price: $%.2f\n", inv->items[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nItem ID not found!\n");
    }
}

int main() {
    struct Inventory inv;
    inv.count = 0;
    int choice;
    do {
        printf("\n=== INVENTORY MANAGEMENT SYSTEM ===\n");
        printf("1. Add Item\n");
        printf("2. Display Inventory\n");
        printf("3. Update Stock\n");
        printf("4. Search Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem(&inv);
                break;
            case 2:
                displayInventory(&inv);
                break;
            case 3:
                updateStock(&inv);
                break;
            case 4:
                searchItem(&inv);
                break;
            case 5:
                printf("\nExiting system.\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}

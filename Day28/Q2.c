#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    double balance;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("\nSystem full. Cannot create more accounts.\n");
        return;
    }

    BankAccount newAccount;
    printf("\nEnter Account Number: ");
    if (scanf("%d", &newAccount.accountNumber) != 1) {
        printf("\nInvalid account number format.\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == newAccount.accountNumber) {
            printf("\nAccount number already exists.\n");
            return;
        }
    }

    printf("Enter Account Holder Name: ");
    while (getchar() != '\n');
    fgets(newAccount.name, NAME_LENGTH, stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = '\0';

    printf("Enter Initial Deposit: ");
    if (scanf("%lf", &newAccount.balance) != 1 || newAccount.balance < 0) {
        printf("\nInvalid initial deposit amount.\n");
        while (getchar() != '\n');
        return;
    }

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("\nAccount successfully created!\n");
}

int findAccountIndex(int accNum) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNum) {
            return i;
        }
    }
    return -1;
}

void checkBalance() {
    int accNum;
    printf("\nEnter Account Number: ");
    if (scanf("%d", &accNum) != 1) {
        printf("\nInvalid input.\n");
        while (getchar() != '\n');
        return;
    }

    int index = findAccountIndex(accNum);
    if (index == -1) {
        printf("\Account not found.\n");
        return;
    }

    printf("\nAccount Holder: %s", accounts[index].name);
    printf("\nCurrent Balance: $%.2f\n", accounts[index].balance);
}

void depositMoney() {
    int accNum;
    double amount;
    printf("\nEnter Account Number: ");
    if (scanf("%d", &accNum) != 1) {
        printf("\nInvalid input.\n");
        while (getchar() != '\n');
        return;
    }

    int index = findAccountIndex(accNum);
    if (index == -1) {
        printf("\nAccount not found.\n");
        return;
    }

    printf("Enter Deposit Amount: ");
    if (scanf("%lf", &amount) != 1 || amount <= 0) {
        printf("\nInvalid deposit amount.\n");
        while (getchar() != '\n');
        return;
    }

    accounts[index].balance += amount;
    printf("\n$%.2f deposited successfully! New Balance: $%.2f\n", amount, accounts[index].balance);
}

void withdrawMoney() {
    int accNum;
    double amount;
    printf("\nEnter Account Number: ");
    if (scanf("%d", &accNum) != 1) {
        printf("\nInvalid input.\n");
        while (getchar() != '\n');
        return;
    }

    int index = findAccountIndex(accNum);
    if (index == -1) {
        printf("\nAccount not found.\n");
        return;
    }

    printf("Enter Withdrawal Amount: ");
    if (scanf("%lf", &amount) != 1 || amount <= 0) {
        printf("\nInvalid withdrawal amount.\n");
        while (getchar() != '\n');
        return;
    }

    if (amount > accounts[index].balance) {
        printf("\nInsufficient balance. Transaction failed.\n");
        return;
    }

    accounts[index].balance -= amount;
    printf("\n$%.2f withdrawn successfully! New Balance: $%.2f\n", amount, accounts[index].balance);
}

int main() {
    int choice;

    do {
        printf("\n=== BANK MANAGEMENT SYSTEM ===");
        printf("\n1. Create New Account");
        printf("\n2. Check Balance");
        printf("\n3. Deposit Money");
        printf("\n4. Withdraw Money");
        printf("\n5. Exit");
        printf("\nEnter choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid choice. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                checkBalance();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawMoney();
                break;
            case 5:
                printf("\nExiting system. Goodbye!\n");
                break;
            default:
                printf("\nInvalid selection. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

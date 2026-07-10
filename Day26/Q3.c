#include <stdio.h>

int main() 
{
    int pin = 1234;
    int entered_pin;
    int choice;
    int attempts = 0;
    double balance = 5000.0;
    double amount;

    while (attempts < 3) 
    {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &entered_pin);

        if (entered_pin == pin) 
        {
            break;
        } 
        else 
        {
            attempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n\n", 3 - attempts);
        }
    }

    if (attempts == 3) 
    {
        printf("Too many incorrect attempts. Your card has been blocked.\n");
        return 0;
    }

    do 
    {
        printf("\n=== ATM SIMULATION ===\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Your current balance is: $%.2f\n", balance);
                break;

            case 2:
                printf("Enter deposit amount: $");
                scanf("%lf", &amount);
                if (amount > 0) 
                {
                    balance += amount;
                    printf("$%.2f deposited successfully.\n", amount);
                } 
                else 
                {
                    printf("Invalid deposit amount.\n");
                }
                break;

            case 3:
                printf("Enter withdrawal amount: $");
                scanf("%lf", &amount);
                if (amount > 0 && amount <= balance) 
                {
                    balance -= amount;
                    printf("$%.2f withdrawn successfully.\n", amount);
                } 
                else if (amount > balance) 
                {
                    printf("Insufficient balance.\n");
                } 
                else 
                {
                    printf("Invalid withdrawal amount.\n");
                }
                break;

            case 4:
                printf("Thank you for using our ATM. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

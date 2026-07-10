#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SEATS 50

struct Passenger {
    int seatNumber;
    char name[50];
    int age;
};

struct Passenger seats[TOTAL_SEATS];
int bookedCount = 0;

void initializeSystem() {
    for (int i = 0; i < TOTAL_SEATS; i++) {
        seats[i].seatNumber = i + 1;
        strcpy(seats[i].name, "");
        seats[i].age = 0;
    }
}

void displaySeats() {
    printf("\n--- Seat Status Layout ---\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (strcmp(seats[i].name, "") == 0) {
            printf("[%02d:Available]  ", seats[i].seatNumber);
        } else {
            printf("[%02d:BOOKED   ]  ", seats[i].seatNumber);
        }
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
}

void bookTicket() {
    if (bookedCount >= TOTAL_SEATS) {
        printf("\nError: All seats are fully booked!\n");
        return;
    }

    int seatNum;
    displaySeats();
    printf("\nEnter preferred seat number (1-%d): ", TOTAL_SEATS);
    if (scanf("%d", &seatNum) != 1) {
        printf("\nInvalid input type!\n");
        while (getchar() != '\n');
        return;
    }

    if (seatNum < 1 || seatNum > TOTAL_SEATS) {
        printf("\nError: Invalid seat number!\n");
        return;
    }

    if (strcmp(seats[seatNum - 1].name, "") != 0) {
        printf("\nError: Seat %d is already taken!\n", seatNum);
        return;
    }

    int idx = seatNum - 1;
    printf("Enter passenger name: ");
    while (getchar() != '\n');
    fgets(seats[idx].name, sizeof(seats[idx].name), stdin);
    seats[idx].name[strcspn(seats[idx].name, "\n")] = '\0';

    printf("Enter passenger age: ");
    if (scanf("%d", &seats[idx].age) != 1) {
        printf("\nInvalid age layout! Booking rolled back.\n");
        strcpy(seats[idx].name, "");
        while (getchar() != '\n');
        return;
    }

    bookedCount++;
    printf("\nSuccess: Ticket booked successfully for Seat %d!\n", seatNum);
}

void cancelTicket() {
    int seatNum;
    printf("\nEnter your seat number to cancel (1-%d): ", TOTAL_SEATS);
    if (scanf("%d", &seatNum) != 1) {
        printf("\nInvalid input type!\n");
        while (getchar() != '\n');
        return;
    }

    if (seatNum < 1 || seatNum > TOTAL_SEATS) {
        printf("\nError: Invalid seat number!\n");
        return;
    }

    int idx = seatNum - 1;
    if (strcmp(seats[idx].name, "") == 0) {
        printf("\nError: Seat %d is already empty!\n", seatNum);
        return;
    }

    strcpy(seats[idx].name, "");
    seats[idx].age = 0;
    bookedCount--;
    printf("\nSuccess: Booking for Seat %d has been canceled.\n", seatNum);
}

void searchTicket() {
    int seatNum;
    printf("\nEnter seat number to search (1-%d): ", TOTAL_SEATS);
    if (scanf("%d", &seatNum) != 1) {
        printf("\nInvalid input type!\n");
        while (getchar() != '\n');
        return;
    }

    if (seatNum < 1 || seatNum > TOTAL_SEATS) {
        printf("\nError: Invalid seat number!\n");
        return;
    }

    int idx = seatNum - 1;
    if (strcmp(seats[idx].name, "") == 0) {
        printf("\nSeat %d is currently available.\n", seatNum);
    } else {
        printf("\n--- Ticket Information ---\n");
        printf("Seat Number: %d\n", seats[idx].seatNumber);
        printf("Passenger Name: %s\n", seats[idx].name);
        printf("Passenger Age: %d\n", seats[idx].age);
    }
}

int main() {
    int choice;
    initializeSystem();

    while (1) {
        printf("\n=============================\n");
        printf("    TICKET BOOKING SYSTEM    \n");
        printf("=============================\n");
        printf("1. View Seat Map\n");
        printf("2. Book a Ticket\n");
        printf("3. Cancel a Ticket\n");
        printf("4. Search Reservation\n");
        printf("5. Exit System\n");
        printf("Enter your option (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid selection! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                searchTicket();
                break;
            case 5:
                printf("\nThank you for using the ticket booking system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select an option from 1 to 5.\n");
        }
    }
    return 0;
}

#include <stdio.h>

#define MAX_SEATS 50

// Global array to store seat status
int seats[MAX_SEATS] = {0}; // 0 represents available, 1 represents booked

// Function to display current seat status
void displaySeats() {
    printf("Seat Status:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        printf("Seat %d: %s\n", i + 1, seats[i] ? "Booked" : "Available");
    }
}

// Function to book a seat
void bookSeat(int seatNumber) {
    if (seatNumber >= 1 && seatNumber <= MAX_SEATS) {
        if (seats[seatNumber - 1] == 0) {
            seats[seatNumber - 1] = 1;
            printf("Seat %d booked successfully.\n", seatNumber);
        } else {
            printf("Seat %d is already booked.\n", seatNumber);
        }
    } else {
        printf("Invalid seat number.\n");
    }
}

// Function to cancel a booked seat
void cancelSeat(int seatNumber) {
    if (seatNumber >= 1 && seatNumber <= MAX_SEATS) {
        if (seats[seatNumber - 1] == 1) {
            seats[seatNumber - 1] = 0;
            printf("Seat %d cancelled successfully.\n", seatNumber);
        } else {
            printf("Seat %d is not booked.\n", seatNumber);
        }
    } else {
        printf("Invalid seat number.\n");
    }
}

int main() {
    int choice, seatNumber;

    do {
        printf("\n--- Movie Ticket Booking System ---\n");
        printf("1. Display Seat Status\n");
        printf("2. Book a Seat\n");
        printf("3. Cancel a Seat\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                printf("Enter seat number to book: ");
                scanf("%d", &seatNumber);
                bookSeat(seatNumber);
                break;
            case 3:
                printf("Enter seat number to cancel: ");
                scanf("%d", &seatNumber);
                cancelSeat(seatNumber);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}


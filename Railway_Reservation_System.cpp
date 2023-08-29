#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 50

struct Passenger {
    char name[50];
    int age;
    char gender;
    int seatNumber;
};

struct Train {
    char trainName[50];
    int totalSeats;
    struct Passenger passengers[MAX_SEATS];
};

void displayMenu() {
    printf("\n********** Railway Reservation System **********\n");
    printf("1. Reserve a seat\n");
    printf("2. Cancel reservation\n");
    printf("3. Display passenger information\n");
    printf("4. Exit\n");
    printf("***********************************************\n");
    printf("Enter your choice: ");
}

void reserveSeat(struct Train* train) {
    if (train->totalSeats == MAX_SEATS) {
        printf("Sorry, no seats available.\n");
        return;
    }

    struct Passenger passenger;

    printf("Enter passenger name: ");
    scanf("%s", passenger.name);

    printf("Enter passenger age: ");
    scanf("%d", &passenger.age);

    printf("Enter passenger gender (M/F): ");
    scanf(" %c", &passenger.gender);

    int seatNumber = train->totalSeats + 1;
    passenger.seatNumber = seatNumber;

    train->passengers[train->totalSeats] = passenger;
    train->totalSeats++;

    printf("Seat reserved successfully. Your seat number is %d.\n", seatNumber);
}

void cancelReservation(struct Train* train) {
    int seatNumber;

    printf("Enter seat number to cancel reservation: ");
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > train->totalSeats) {
        printf("Invalid seat number.\n");
        return;
    }

    for (int i = seatNumber - 1; i < train->totalSeats - 1; i++) {
        train->passengers[i] = train->passengers[i + 1];
    }

    train->totalSeats--;
    printf("Reservation cancelled successfully.\n");
}

void displayPassengerInfo(struct Train train) {
    int seatNumber;

    printf("Enter seat number to display passenger information: ");
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > train.totalSeats) {
        printf("Invalid seat number.\n");
        return;
    }

    struct Passenger passenger = train.passengers[seatNumber - 1];

    printf("\nPassenger Information\n");
    printf("Name: %s\n", passenger.name);
    printf("Age: %d\n", passenger.age);
    printf("Gender: %c\n", passenger.gender);
    printf("Seat Number: %d\n", passenger.seatNumber);
}

int main() {
    struct Train train;
    strcpy(train.trainName, "Express");

    train.totalSeats = 0;

    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                reserveSeat(&train);
                break;
            case 2:
                cancelReservation(&train);
                break;
            case 3:
                displayPassengerInfo(train);
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

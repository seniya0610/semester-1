#include <stdio.h>
#include <string.h>

// Define the package structure
typedef struct {
    char packageName;
    char destination[1000];
    int duration; // in days
    float cost;
    int availableSeats;
} TravelPackage;

// Initialize packages
TravelPackage packages[3] = {
    {'A', "Paris", 3, 1200.0, 4},
    {'B', "Maldives", 5, 7000.0, 2},
    {'C', "Bali", 1, 700.0, 7}
};

// Function to display all packages
void displayPackages(TravelPackage packages[]) {
    for (int i = 0; i < 3; i++) {
        printf("Package Name: %c\n", packages[i].packageName);
        printf("Destination: %s\n", packages[i].destination);
        printf("Duration: %d days\n", packages[i].duration);
        printf("Cost: $%.2f\n", packages[i].cost);
        printf("Seats Available: %d\n", packages[i].availableSeats);
        printf("\n");
    }
}

// Function to book a package
void bookPackage(TravelPackage packages[]) {
    char selectedPackage;
    int requiredSeats;

    printf("Which package do you choose? ");
    scanf(" %c", &selectedPackage);

    int packageIndex = -1;
    for (int i = 0; i < 3; i++) {
        if (selectedPackage == packages[i].packageName) {
            packageIndex = i;
            break;
        }
    }

    if (packageIndex == -1) {
        printf("Invalid package selection.\n");
    } else {
        printf("How many seats do you need? ");
        scanf("%d", &requiredSeats);

        if (requiredSeats > packages[packageIndex].availableSeats) {
            printf("Insufficient seats available.\n");
        } else {
            packages[packageIndex].availableSeats -= requiredSeats;
            printf("Booking successful!\n");
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nEnter choice (1 to View Packages, 2 to Book Package, 3 to Exit): ");
        scanf("%d", &choice);

        if (choice == 1) {
            displayPackages(packages);
        } else if (choice == 2) {
            bookPackage(packages);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

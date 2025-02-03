#include <stdio.h>
#include <string.h>

// Define a structure for car details
struct Car {
    int year;
    int price;
    int mileage;
    char make[20];
    char model[20];
};

int main() {
    int carCount = 2; // Number of cars in the dealership
    struct Car dealership[carCount];

    // Input details for each car
    for (int i = 0; i < carCount; i++) {
        printf("Enter details for car %d:\n", i + 1);
        printf("Enter Make: ");
        scanf("%s", dealership[i].make);
        printf("Enter Model: ");
        scanf("%s", dealership[i].model);
        printf("Enter Year: ");
        scanf("%d", &dealership[i].year);
        printf("Enter Price: ");
        scanf("%d", &dealership[i].price);
        printf("Enter Mileage: ");
        scanf("%d", &dealership[i].mileage);
        printf("\n");
    }

    // Display all cars in the dealership
    printf("Cars in the dealership:\n");
    for (int i = 0; i < carCount; i++) {
        printf("Car %d:\n", i + 1);
        printf("Make: %s\n", dealership[i].make);
        printf("Model: %s\n", dealership[i].model);
        printf("Year: %d\n", dealership[i].year);
        printf("Price: %d\n", dealership[i].price);
        printf("Mileage: %d\n", dealership[i].mileage);
        printf("\n");
    }

    // Search for a car by make
    char searchMake[20];
    printf("Enter Make to search: ");
    scanf("%s", searchMake);

    int found = 0;
    int searchIndex;

    for (int i = 0; i < carCount; i++) {
        if (strcmp(dealership[i].make, searchMake) == 0) {
            found = 1;
            searchIndex = i;
            break;
        }
    }

    // Display search result
    if (found) {
        printf("Car found:\n");
        printf("Make: %s\n", dealership[searchIndex].make);
        printf("Model: %s\n", dealership[searchIndex].model);
        printf("Year: %d\n", dealership[searchIndex].year);
        printf("Price: %d\n", dealership[searchIndex].price);
        printf("Mileage: %d\n", dealership[searchIndex].mileage);
    } else {
        printf("Car not found.\n");
    }

    return 0;
}

#include <stdio.h>

#define METER_TO_KILOMETER 0.001

// Function to convert meters to kilometers
void convertToKilometers(float meters) {
    static int callCount = 0;
    callCount++;
    float kilometers = meters * METER_TO_KILOMETER;
    printf("%.2f meters converted to %.2f kilometers\n", meters, kilometers);
    printf("This function has been called %d time(s).\n", callCount);
}

int main() {
    char continueConversion;
    float meters;

    while (1) {
        // Input: Distance in meters
        printf("Enter distance in meters: ");
        scanf("%f", &meters);

        // Convert and display result
        convertToKilometers(meters);

        // Prompt to continue or stop
        printf("Do you wish to continue? (Y or N): ");
        scanf(" %c", &continueConversion);

        if (continueConversion == 'N' || continueConversion == 'n') {
            break;
        }
    }

    return 0;
}

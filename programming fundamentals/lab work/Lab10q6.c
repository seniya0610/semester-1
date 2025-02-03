#include <stdio.h>

#define MAX_TEMPERATURE 40

// Function to check if the temperature exceeds the limit
void checkTemperature(float currentTemp, int numTemps) {
    static int exceedCount = 0;
    if (currentTemp > MAX_TEMPERATURE) {
        exceedCount++;
        printf("%.2f Exceeded range. Current temperatures exceeding max: %d\n", currentTemp, exceedCount);
    } else {
        printf("%.2f Did not exceed. Current temperatures exceeding max: %d\n", currentTemp, exceedCount);
    }
}

int main() {
    int numTemperatures;

    // Input: Number of temperatures
    printf("How many temperature readings? ");
    scanf("%d", &numTemperatures);

    float temperatures[numTemperatures];

    // Input: Temperature values
    for (int i = 0; i < numTemperatures; i++) {
        printf("Enter temperature %d: ", i + 1);
        scanf("%f", &temperatures[i]);
    }

    // Check each temperature
    for (int i = 0; i < numTemperatures; i++) {
        checkTemperature(temperatures[i], numTemperatures);
    }

    return 0;
}

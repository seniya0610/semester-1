#include <stdio.h>
#include <math.h>

// Define a structure for a 3D point
typedef struct {
    float x, y, z;
} Point;

// Define a structure for a vehicle
typedef struct {
    int vehicleID;
    Point startPoint;
    Point endPoint;
    float timeTaken; // in hours
} Vehicle;

// Function to input details for N vehicles
void inputVehicles(Vehicle *vehicles, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for Vehicle %d\n", i + 1);
        printf("Vehicle ID: ");
        scanf("%d", &vehicles[i].vehicleID);
        
        printf("Enter start point (x, y, z): ");
        scanf("%f %f %f", &vehicles[i].startPoint.x, &vehicles[i].startPoint.y, &vehicles[i].startPoint.z);
        
        printf("Enter end point (x, y, z): ");
        scanf("%f %f %f", &vehicles[i].endPoint.x, &vehicles[i].endPoint.y, &vehicles[i].endPoint.z);
        
        printf("Enter time taken (in hours): ");
        scanf("%f", &vehicles[i].timeTaken);
    }
}

// Function to calculate the 3D distance between start and end points
float calculateDistance(Point start, Point end) {
    return sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2) + pow(end.z - start.z, 2));
}

// Function to calculate the speed of each vehicle
float calculateSpeed(Vehicle vehicle) {
    float distance = calculateDistance(vehicle.startPoint, vehicle.endPoint);
    return distance / vehicle.timeTaken; // speed = distance / time
}

// Function to find the fastest vehicle
Vehicle findFastestVehicle(Vehicle *vehicles, int n) {
    Vehicle fastestVehicle = vehicles[0];
    float maxSpeed = calculateSpeed(fastestVehicle);
    
    for (int i = 1; i < n; i++) {
        float speed = calculateSpeed(vehicles[i]);
        if (speed > maxSpeed) {
            fastestVehicle = vehicles[i];
            maxSpeed = speed;
        }
    }
    
    return fastestVehicle;
}

// Function to find vehicles that traveled a distance greater than a given threshold
void findVehiclesAboveThreshold(Vehicle *vehicles, int n, float threshold) {
    printf("\nVehicles that traveled a distance greater than %.2f:\n", threshold);
    for (int i = 0; i < n; i++) {
        float distance = calculateDistance(vehicles[i].startPoint, vehicles[i].endPoint);
        if (distance > threshold) {
            printf("Vehicle ID: %d, Distance: %.2f\n", vehicles[i].vehicleID, distance);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of vehicles: ");
    scanf("%d", &n);
    
    // Dynamically allocate memory for the vehicles array
    Vehicle *vehicles = (Vehicle *)malloc(n * sizeof(Vehicle));
    
    // Input details for vehicles
    inputVehicles(vehicles, n);
    
    // Calculate and display the distance, speed for each vehicle
    for (int i = 0; i < n; i++) {
        float distance = calculateDistance(vehicles[i].startPoint, vehicles[i].endPoint);
        float speed = calculateSpeed(vehicles[i]);
        printf("\nVehicle %d Details:\n", vehicles[i].vehicleID);
        printf("Distance Traveled: %.2f\n", distance);
        printf("Speed: %.2f\n", speed);
    }
    
    // Find and display the fastest vehicle
    Vehicle fastest = findFastestVehicle(vehicles, n);
    printf("\nFastest Vehicle ID: %d\n", fastest.vehicleID);
    
    // Find vehicles that traveled a distance greater than a given threshold
    float threshold;
    printf("\nEnter the distance threshold: ");
    scanf("%f", &threshold);
    findVehiclesAboveThreshold(vehicles, n, threshold);
    
    // Free dynamically allocated memory
    free(vehicles);
    
    return 0;
}

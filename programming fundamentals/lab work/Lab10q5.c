#include <stdio.h>
#include <math.h>

// Define the point structure
typedef struct {
    float x;
    float y;
} Point;

// Function to calculate the distance between two points
float calculateDistance(Point pointA, Point pointB) {
    return sqrt(pow(pointA.x - pointB.x, 2) + pow(pointA.y - pointB.y, 2));
}

// Function to check if points are within a rectangle
void checkRectangle(Point pointA, Point pointB) {
    Point topLeft, bottomRight;

    printf("Enter Top Left x-coordinate: ");
    scanf("%f", &topLeft.x);
    printf("Enter Top Left y-coordinate: ");
    scanf("%f", &topLeft.y);
    printf("Enter Bottom Right x-coordinate: ");
    scanf("%f", &bottomRight.x);
    printf("Enter Bottom Right y-coordinate: ");
    scanf("%f", &bottomRight.y);

    if (pointA.x >= topLeft.x && pointA.x <= bottomRight.x &&
        pointA.y <= topLeft.y && pointA.y >= bottomRight.y) {
        printf("Point A is inside the rectangular boundary.\n");
    } else {
        printf("Point A is outside the rectangular boundary.\n");
    }

    if (pointB.x >= topLeft.x && pointB.x <= bottomRight.x &&
        pointB.y <= topLeft.y && pointB.y >= bottomRight.y) {
        printf("Point B is inside the rectangular boundary.\n");
    } else {
        printf("Point B is outside the rectangular boundary.\n");
    }
}

int main() {
    Point pointA, pointB;

    // Input points
    printf("Enter Point A x-coordinate: ");
    scanf("%f", &pointA.x);
    printf("Enter Point A y-coordinate: ");
    scanf("%f", &pointA.y);
    printf("Enter Point B x-coordinate: ");
    scanf("%f", &pointB.x);
    printf("Enter Point B y-coordinate: ");
    scanf("%f", &pointB.y);

    // Calculate and display distance
    printf("The distance between Point A and Point B is: %.2f\n", calculateDistance(pointA, pointB));

    // Check if points are within the rectangle
    checkRectangle(pointA, pointB);

    return 0;
}

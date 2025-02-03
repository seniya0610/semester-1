#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// Define a structure for a point
typedef struct {
    float x, y;
} Point;

// Define a structure for a shape (name and vertices)
typedef struct {
    char name[20];    // Name of the shape (max 20 characters)
    Point *vertices;  // Pointer to dynamically allocated vertices array
    int vertexCount;  // Number of vertices (3 for triangle, 4 for rectangle)
} Shape;

// Function to input details for N shapes
void inputShapes(Shape *shapes, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter name of shape %d (max 19 characters): ", i+1);
        getchar();  // Clear the newline character left in the buffer
        fgets(shapes[i].name, 20, stdin);
        shapes[i].name[strcspn(shapes[i].name, "\n")] = '\0';  // Remove newline

        printf("Enter number of vertices (3 for triangle, 4 for rectangle): ");
        scanf("%d", &shapes[i].vertexCount);

        // Dynamically allocate memory for vertices based on vertexCount
        shapes[i].vertices = (Point *)malloc(shapes[i].vertexCount * sizeof(Point));

        for (int j = 0; j < shapes[i].vertexCount; j++) {
            printf("Enter coordinates for vertex %d (x y): ", j+1);
            scanf("%f %f", &shapes[i].vertices[j].x, &shapes[i].vertices[j].y);
        }
    }
}

// Function to calculate the perimeter of a shape
float calculatePerimeter(Shape shape) {
    float perimeter = 0;
    
    for (int i = 0; i < shape.vertexCount; i++) {
        int next = (i + 1) % shape.vertexCount; // To connect the last vertex back to the first
        float dx = shape.vertices[next].x - shape.vertices[i].x;
        float dy = shape.vertices[next].y - shape.vertices[i].y;
        perimeter += sqrt(dx * dx + dy * dy);
    }
    
    return perimeter;
}

// Function to calculate the area of a shape
float calculateArea(Shape shape) {
    float area = 0;

    if (shape.vertexCount == 3) {
        // Area of triangle using determinant (Shoelace theorem)
        area = fabs((shape.vertices[0].x * (shape.vertices[1].y - shape.vertices[2].y) +
                     shape.vertices[1].x * (shape.vertices[2].y - shape.vertices[0].y) +
                     shape.vertices[2].x * (shape.vertices[0].y - shape.vertices[1].y)) / 2.0);
    } else if (shape.vertexCount == 4) {
        // Area of rectangle: width * height
        float width = sqrt(pow(shape.vertices[0].x - shape.vertices[1].x, 2) +
                           pow(shape.vertices[0].y - shape.vertices[1].y, 2));
        float height = sqrt(pow(shape.vertices[1].x - shape.vertices[2].x, 2) +
                            pow(shape.vertices[1].y - shape.vertices[2].y, 2));
        area = width * height;
    }
    
    return area;
}

// Function to find the shape with the largest area
Shape findLargestAreaShape(Shape *shapes, int n) {
    Shape largestShape = shapes[0];
    float largestArea = calculateArea(largestShape);
    
    for (int i = 1; i < n; i++) {
        float area = calculateArea(shapes[i]);
        if (area > largestArea) {
            largestShape = shapes[i];
            largestArea = area;
        }
    }

    return largestShape;
}

// Function to check if a point is inside a rectangle
int isPointInsideRectangle(Shape rectangle, Point p) {
    if (rectangle.vertexCount != 4) {
        printf("This shape is not a rectangle!\n");
        return 0;
    }

    // Check if point is inside the rectangle using the axis-aligned bounding box (AABB) method
    float minX = rectangle.vertices[0].x, maxX = rectangle.vertices[0].x;
    float minY = rectangle.vertices[0].y, maxY = rectangle.vertices[0].y;

    for (int i = 1; i < 4; i++) {
        if (rectangle.vertices[i].x < minX) minX = rectangle.vertices[i].x;
        if (rectangle.vertices[i].x > maxX) maxX = rectangle.vertices[i].x;
        if (rectangle.vertices[i].y < minY) minY = rectangle.vertices[i].y;
        if (rectangle.vertices[i].y > maxY) maxY = rectangle.vertices[i].y;
    }

    return (p.x >= minX && p.x <= maxX && p.y >= minY && p.y <= maxY);
}

int main() {
    int n;
    printf("Enter the number of shapes: ");
    scanf("%d", &n);

    // Dynamically allocate memory for shapes
    Shape *shapes = (Shape *)malloc(n * sizeof(Shape));
    
    inputShapes(shapes, n);

    printf("\nDetails of Shapes:\n");
    for (int i = 0; i < n; i++) {
        printf("Shape %d: %s\n", i + 1, shapes[i].name);
        printf("Perimeter: %.2f\n", calculatePerimeter(shapes[i]));
        printf("Area: %.2f\n", calculateArea(shapes[i]));
    }

    Shape largestShape = findLargestAreaShape(shapes, n);
    printf("\nShape with the largest area: %s\n", largestShape.name);
    printf("Area: %.2f\n", calculateArea(largestShape));

    Point testPoint;
    printf("\nEnter a point (x y) to check if it lies inside a rectangle: ");
    scanf("%f %f", &testPoint.x, &testPoint.y);

    // Check for the first rectangle
    for (int i = 0; i < n; i++) {
        if (shapes[i].vertexCount == 4) {
            if (isPointInsideRectangle(shapes[i], testPoint)) {
                printf("The point is inside the rectangle.\n");
            } else {
                printf("The point is outside the rectangle.\n");
            }
            break;
        }
    }

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        free(shapes[i].vertices);
    }
    free(shapes);

    return 0;
}

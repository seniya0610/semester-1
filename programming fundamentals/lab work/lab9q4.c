#include <stdio.h>

float calculate(float num1, float num2, char operation) {
    float result;

    switch(operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: Division by zero is not allowed.\n");
                result = 0;
            }
            break;
        default:
            printf("Error: Invalid operation.\n");
            result = 0;
    }
    return result;
}

int main() {
    float num1, num2, result;
    char operation;
    
    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter second number: ");
    scanf("%f", &num2);

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);
    
    result = calculate(num1, num2, operation);

    printf("Result: %.2f\n", result);

    return 0;
}

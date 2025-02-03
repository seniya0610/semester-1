#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // For atoi (optional)

int BinaryToDecimal(int number);
void DecimalToBinary(int number);
void DecimalToHexadecimal(int number);
int HexadecimalToDecimal(char hexNumber[]);
void BinaryToHexadecimal(int number);
void HexadecimalToBinary(char hexNumber[]);

int main() {
    int choice, number;
    char hexNumber[20];

    do {
        printf("\n--- Numerical Conversion Menu ---\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Hexadecimal to Decimal\n");
        printf("5. Binary to Hexadecimal\n");
        printf("6. Hexadecimal to Binary\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%d", &number);
                printf("Decimal: %d\n", BinaryToDecimal(number));
                break;

            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                DecimalToBinary(number);
                break;

            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                DecimalToHexadecimal(number);
                break;

            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                printf("Decimal: %d\n", HexadecimalToDecimal(hexNumber));
                break;

            case 5:
                printf("Enter a binary number: ");
                scanf("%d", &number);
                BinaryToHexadecimal(number);
                break;

            case 6:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToBinary(hexNumber);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

int BinaryToDecimal(int number) {
    int decimal = 0;
    int i = 0;

    while (number != 0) {
        int remaining = number % 10;
        decimal += remaining * pow(2, i);
        i++;
        number /= 10;
    }

    return decimal;
}

void DecimalToBinary(int number) {
    int binary[32];
    int length = 0;

    if (number == 0) {
        printf("Binary equivalent: 0\n");
        return;
    }

    while (number > 0) {
        binary[length++] = number % 2;
        number /= 2;
    }

    printf("Binary equivalent: ");
    for (int j = length - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

void DecimalToHexadecimal(int number) {
    if (number == 0) {
        printf("0\n");
        return;
    }

    char hex[20];
    int i = 0;
    const char hexChars[] = "0123456789ABCDEF";

    while (number != 0) {
        int temp = number % 16;
        hex[i++] = hexChars[temp];
        number /= 16;
    }

    printf("Hexadecimal equivalent: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
}

int HexadecimalToDecimal(char hexNumber[]) {
    int decimal = 0;
    int length = strlen(hexNumber);

    for (int i = 0; i < length; i++) {
        char currentChar = hexNumber[i];
        int hexValue;

        if (currentChar >= '0' && currentChar <= '9') {
            hexValue = currentChar - '0';
        } else if (currentChar >= 'A' && currentChar <= 'F') {
            hexValue = currentChar - 'A' + 10;
        } else if (currentChar >= 'a' && currentChar <= 'f') {
            hexValue = currentChar - 'a' + 10;
        } else {
            printf("Invalid hexadecimal character: %c\n", currentChar);
            return 0;
        }

        decimal = decimal * 16 + hexValue;
    }

    return decimal;
}

void BinaryToHexadecimal(int number) {
    int decimal = BinaryToDecimal(number);
    DecimalToHexadecimal(decimal);
}

void HexadecimalToBinary(char hexNumber[]) {
    int decimal = HexadecimalToDecimal(hexNumber);
    DecimalToBinary(decimal);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct {
	int id;
	char name[MAX_NAME_LENGTH];
	float price;
	int quantity;
} Product;

void addInventory(const char *filename) {
	FILE *fptr = fopen(filename, "a+");
	if (fptr == NULL) {
		perror("Error opening file");
		return;
	}

	Product newProduct;

	printf("Enter Product ID: ");
	scanf("%d", &newProduct.id);
	getchar();
	
	printf("Enter Product Name: ");
	fgets(newProduct.name, sizeof(newProduct.name), stdin);
	newProduct.name[strcspn(newProduct.name, "\n")] = '\0';
	
	printf("Enter Product Price: ");
	scanf("%f", &newProduct.price);

	printf("Enter Product Quantity: ");
	scanf("%d", &newProduct.quantity);

	fprintf(fptr, "%d,%s,%.2f,%d\n", newProduct.id, newProduct.name, newProduct.price, newProduct.quantity);
	fclose(fptr);

	printf("Product added successfully!\n");
}

void appendData(const char *filename) {
	FILE *fptr = fopen(filename, "r+");
	if (fptr == NULL) {
		perror("Error opening file");
		return;
	}

	int productId;
	Product updatedProduct;
	
	printf("Enter Product ID to append data: ");
	scanf("%d", &productId);

	// Find the product to append data
	int found = 0;
	while (fscanf(fptr, "%d,%99[^,],%f,%d\n", &updatedProduct.id, updatedProduct.name, &updatedProduct.price, &updatedProduct.quantity) != EOF) {
		if (updatedProduct.id == productId) {
			found = 1;
			break;
		}
	}

	if (!found) {
		printf("Product ID not found!\n");
		fclose(fptr);
		return;
	}

	printf("Product found: %d, %s, %.2f, %d\n", updatedProduct.id, updatedProduct.name, updatedProduct.price, updatedProduct.quantity);

	// Appending new data to the found product
	printf("Enter additional quantity to add: ");
	int additionalQuantity;
	scanf("%d", &additionalQuantity);

	updatedProduct.quantity += additionalQuantity;

	// Move back to the correct position to overwrite product entry
	fseek(fptr, -(long)sizeof(Product), SEEK_CUR);
	fprintf(fptr, "%d,%s,%.2f,%d\n", updatedProduct.id, updatedProduct.name, updatedProduct.price, updatedProduct.quantity);
	fclose(fptr);

	printf("Product data updated successfully!\n");
}

void removeData(const char *filename) {
	FILE *fptr = fopen(filename, "r");
	FILE *tempFile = fopen("temp.txt", "w");
	if (fptr == NULL || tempFile == NULL) {
		perror("Error opening file");
		return;
	}

	int productId;
	printf("Enter Product ID to remove: ");
	scanf("%d", &productId);

	Product product;
	int found = 0;

	while (fscanf(fptr, "%d,%99[^,],%f,%d\n", &product.id, product.name, &product.price, &product.quantity) != EOF) {
		if (product.id != productId) {
			fprintf(tempFile, "%d,%s,%.2f,%d\n", product.id, product.name, product.price, product.quantity);
		} else {
			found = 1;
		}
	}

	if (found) {
		printf("Product with ID %d removed successfully!\n", productId);
	} else {
		printf("Product ID not found!\n");
	}

	fclose(fptr);
	fclose(tempFile);

	// Remove the old file and rename the temp file
	remove(filename);
	rename("temp.txt", filename);
}

void searchDataByInitial(const char *filename) {
	FILE *fptr = fopen(filename, "r");
	if (fptr == NULL) {
		perror("Error opening file");
		return;
	}

	char searchChar;
	printf("Enter the initial character to search for: ");
	getchar();  // Clear any leftover newline
	searchChar = getchar();

	Product product;
	int found = 0;

	while (fscanf(fptr, "%d,%99[^,],%f,%d\n", &product.id, product.name, &product.price, &product.quantity) != EOF) {
		if (product.name[0] == searchChar) {
			printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n", product.id, product.name, product.price, product.quantity);
			found = 1;
		}
	}

	if (!found) {
		printf("No products found with the initial character '%c'.\n", searchChar);
	}

	fclose(fptr);
}

int main() {
	const char *filename = "inventory.txt";
	int choice;

	while (1) {
		printf("\nInventory Management System\n");
		printf("1. Add Inventory\n");
		printf("2. Append Data\n");
		printf("3. Remove Data\n");
		printf("4. Search Data by Initial Character\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			addInventory(filename);
			break;
		case 2:
			appendData(filename);
			break;
		case 3:
			removeData(filename);
			break;
		case 4:
			searchDataByInitial(filename);
			break;
		case 5:
			printf("Exiting program.\n");
			exit(0);
		default:
			printf("Invalid choice. Please try again.\n");
		}
	}

	return 0;
}

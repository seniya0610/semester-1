#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ***speciesSupplies;
    int numsupplies;
    int numSpecies;
} pet;

void addSpeciesAndSupplies(pet *inventory) {
    int speciesIndex;
    printf("Enter the number of species to add: ");
    scanf("%d", &speciesIndex);

    // Allocate memory for species supplies and add to the total species count
    inventory->numSpecies += speciesIndex;
    inventory->speciesSupplies = (char ***)realloc(inventory->speciesSupplies, inventory->numSpecies * sizeof(char **));

    for (int i = inventory->numSpecies - speciesIndex; i < inventory->numSpecies; i++) {
        printf("Enter the number of supplies for species %d: ", i + 1);
        scanf("%d", &inventory->numsupplies);

        // Allocate memory for supplies of the species
        inventory->speciesSupplies[i] = (char **)malloc(inventory->numsupplies * sizeof(char *));
        
        for (int j = 0; j < inventory->numsupplies; j++) {
            inventory->speciesSupplies[i][j] = (char *)malloc(50 * sizeof(char));  // Allocate memory for each supply
            printf("Enter supply %d for species %d: ", j + 1, i + 1);
            scanf("%s", inventory->speciesSupplies[i][j]);
        }
    }
}

void displayInventory(pet *inventory) {
    printf("Current Inventory:\n");
    for (int i = 0; i < inventory->numSpecies; i++) {
        printf("Species %d:\n", i + 1);
        for (int j = 0; j < inventory->numsupplies; j++) {
            printf("  - %s\n", inventory->speciesSupplies[i][j]);
        }
    }
}

void updateSupplies(pet *inventory) {
    int speciesIndex;
    printf("Enter the species index to update supplies: ");
    scanf("%d", &speciesIndex);

    if (speciesIndex < 0 || speciesIndex >= inventory->numSpecies) {
        printf("Invalid species index.\n");
        return;
    }

    int supplyIndex;
    printf("Enter the supply index to update: ");
    scanf("%d", &supplyIndex);

    if (supplyIndex < 0 || supplyIndex >= inventory->numsupplies) {
        printf("Invalid supply index.\n");
        return;
    }

    char newSupply[50];
    printf("Enter the new name for the supply: ");
    scanf("%s", newSupply);

    // Free previous supply memory and assign new one
    free(inventory->speciesSupplies[speciesIndex][supplyIndex]);
    inventory->speciesSupplies[speciesIndex][supplyIndex] = (char *)malloc(50 * sizeof(char));
    strcpy(inventory->speciesSupplies[speciesIndex][supplyIndex], newSupply);
}

void removeSpecies(pet *inventory) {
    int speciesIndex;
    printf("Enter the index of the species to remove: ");
    scanf("%d", &speciesIndex);

    if (speciesIndex < 0 || speciesIndex >= inventory->numSpecies) {
        printf("Invalid species index.\n");
        return;
    }

    // Free the supplies of the species
    for (int i = 0; i < inventory->numsupplies; i++) {
        free(inventory->speciesSupplies[speciesIndex][i]);
    }
    free(inventory->speciesSupplies[speciesIndex]);

    // Shift species down and reallocate memory
    for (int i = speciesIndex; i < inventory->numSpecies - 1; i++) {
        inventory->speciesSupplies[i] = inventory->speciesSupplies[i + 1];
    }

    inventory->numSpecies--;
    inventory->speciesSupplies = (char ***)realloc(inventory->speciesSupplies, inventory->numSpecies * sizeof(char **));
}

int main() {
    pet inventory;
    inventory.speciesSupplies = NULL;
    inventory.numSpecies = 0;
    inventory.numsupplies = 0;
    int choice;

    do {
        printf("\nPet Shop Inventory System - Pets in Heart\n");
        printf("1. Add Species\n");
        printf("2. Update Supplies\n");
        printf("3. Remove Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addSpeciesAndSupplies(&inventory);
            break;
        case 2:
            updateSupplies(&inventory);
            break;
        case 3:
            removeSpecies(&inventory);
            break;
        case 4:
            displayInventory(&inventory);
            break;
        case 5:
            // Free all allocated memory before exiting
            for (int i = 0; i < inventory.numSpecies; i++) {
                for (int j = 0; j < inventory.numsupplies; j++) {
                    free(inventory.speciesSupplies[i][j]);
                }
                free(inventory.speciesSupplies[i]);
            }
            free(inventory.speciesSupplies);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

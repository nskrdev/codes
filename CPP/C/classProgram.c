#include <stdio.h>

#define MAX_PRODUCTS 5

// Function prototypes
void updateStock(int productIDs[], int stock[], int size);
void displayHighestStock(int productIDs[], int stock[], int size);
void displayOutOfStock(int productIDs[], int stock[], int size);

int main() {
    int productIDs[MAX_PRODUCTS] = {101, 102, 103, 104, 105}; // Sample product IDs
    int stock[MAX_PRODUCTS] = {10, 5, 0, 20, 15}; // Sample stock levels
    
    int choice;
    do {
        printf("\nStore Inventory Management\n");
        printf("1. Update Stock\n");
        printf("2. Display Product with Highest Stock\n");
        printf("3. Show Out of Stock Products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                updateStock(productIDs, stock, MAX_PRODUCTS);
                break;
            case 2:
                displayHighestStock(productIDs, stock, MAX_PRODUCTS);
                break;
            case 3:
                displayOutOfStock(productIDs, stock, MAX_PRODUCTS);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void updateStock(int productIDs[], int stock[], int size) {
    int id, qty, found = 0;
    printf("Enter Product ID: ");
    scanf("%d", &id);
    for (int i = 0; i < size; i++) {
        if (productIDs[i] == id) {
            printf("Enter quantity to add (negative to sell): ");
            scanf("%d", &qty);
            stock[i] += qty;
            if (stock[i] < 0) stock[i] = 0; // Ensure stock doesn't go negative
            printf("Updated stock for Product %d: %d\n", id, stock[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product ID not found!\n");
    }
}

void displayHighestStock(int productIDs[], int stock[], int size) {
    int maxStock = stock[0], maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (stock[i] > maxStock) {
            maxStock = stock[i];
            maxIndex = i;
        }
    }
    printf("Product with highest stock: ID %d, Stock %d\n", productIDs[maxIndex], maxStock);
}

void displayOutOfStock(int productIDs[], int stock[], int size) {
    int found = 0;
    printf("Out of Stock Products:\n");
    for (int i = 0; i < size; i++) {
        if (stock[i] == 0) {
            printf("Product ID: %d\n", productIDs[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No products are out of stock.\n");
    }
}

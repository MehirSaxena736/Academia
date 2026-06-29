include <stdio.h>

// Define the 'product' structure
struct Product {
    char name[50];
    float pricePerUnit;
    int quantityPurchased;
    float amountSpent;
};

int main() {
    // Declare a 'product' variable
    struct Product item;

    // Input the details of the product
    printf("Enter the product name: ");
    scanf("%s", item.name);
    printf("Enter the price per unit: ");
    scanf("%f", &item.pricePerUnit);
    printf("Enter the quantity purchased: ");
    scanf("%d", &item.quantityPurchased);

    // Calculate the amount spent
    item.amountSpent = item.pricePerUnit * item.quantityPurchased;

    // Display the product details
    printf("\nProduct Details:\n");
    printf("Name: %s\n", item.name);
    printf("Price per unit: $%.2f\n", item.pricePerUnit);
    printf("Quantity purchased: %d\n", item.quantityPurchased);
    printf("Amount spent: $%.2f\n", item.amountSpent);

    return 0;
}

#include <stdio.h>
#include <stdbool.h>

// Main function
int main() {
    printf("\n-------------------------\n");
    printf("Inflation + Tax Calculator\nhttps://github.com/luqmanually/inflation-calculator\n");
    printf("-------------------------\n");

    double itemPrice; //Price of item
    printf("\nEnter the price of the item: ");
    scanf("%lf", &itemPrice);

    double taxRate; //Tax rate
    printf("Enter the tax rate: ");
    scanf("%lf", &taxRate);

    if (itemPrice < 0) { // Check if item price is valid
        printf("Invalid input. Price must be greater than or equal to 0.\n");
        return 1;
    }

    if (taxRate < 0 || taxRate > 100) { // Check if tax rate is valid
        printf("Invalid input. Tax rate must be between 0 and 100.\n");
        return 1;
    }

    // Calculate tax amount and total amount
    double taxAmount = itemPrice * taxRate / 100;
    double totalAmount = itemPrice + taxAmount;

    printf("Item Price after tax: %.2lf\n", totalAmount);

    int calculationType; // Find future or past prices
    printf("\nEnter 1 to find future prices or 2 to find past prices: ");
    scanf("%d", &calculationType);

    if(calculationType != 1 && calculationType != 2) { // Check if calculation type is valid
        printf("Invalid input. Please enter 1 or 2.\n");
        return 1;
    }

    int inflationYears; // Number of years for inflation
    printf("Enter the number of years for inflation: ");
    scanf("%d", &inflationYears);

    if (inflationYears < 0) { // Check if inflation years are valid
        printf("Invalid input. Inflation years must be greater than or equal to 0.\n");
        return 1;
    }

    // Set price to after tax
    double price = totalAmount;

    switch (calculationType) {

        case 1: // Future prices
            price = itemPrice;

            // Add inflation rate for every year
            int i;
            for (i = 1; i <= inflationYears; i++) {
                price += (price * 0.045);
            };

            printf("\nTotal price after %d years of inflation: %.2lf\n", inflationYears, price);
            break;

        case 2: // Past prices
            price = itemPrice;

            // Subtract inflation rate for every year
            for (i = 1; i <= inflationYears; i++) {
                price -= (price * 0.045);
            };

            printf("\nTotal price %d years prior to inflation: %.2lf\n", inflationYears, price);
            break;
    }

    return 0;
}
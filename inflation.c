#include <stdio.h>
#include <stdbool.h>

//Main function
int main() {
    float itemPrice; //Price of item
    printf("Enter the price for this purchase?\n-> ");
    scanf(" %f", &itemPrice);

    int action; //Find future or past prices
    printf("\n[1] Check future price with Rule 72 [2] Find out the old prices\n-> ");
    scanf(" %d", &action);

    int inflationYears; //Years in the future
    printf("\nFind out price in # years?\n-> ");
    scanf(" %d", &inflationYears);

    if (action == 1) { // Calculating the future price
        float priceFuture = itemPrice;

        // Add inflation rate for every year
        int i;
        for (i = 1; i <= inflationYears; i++) {
            priceFuture += (priceFuture * 0.045);
        }

        printf("\nTotal price after %d years: %f\n", inflationYears, priceFuture);

    } else { //Calculating the past price

        float pricePast = itemPrice;
        
        // Deducts inflation rate for every months
        int i;
        for (i = 1; i <= inflationYears; i++) {
            pricePast -= (pricePast * 0.045);
        }
        
        printf("\nTotal price %d years prior: %f\n", inflationYears, pricePast);
    }

    return 0;
}
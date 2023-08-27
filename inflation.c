#include <stdio.h>
#include <stdbool.h>

int main() {
    //  User Input: Price of item
    float itemPrice;
    printf("Enter the price for this purchase?\n-> ");
    scanf(" %f", &itemPrice);

    int action;
    printf("[1] Check future price with Rule 72 [2] Find out the old prices\n-> ");
    scanf(" %d", &action);

    int inflationYears;
    printf("Find out price in # years?\n-> ");
    scanf(" %d", &inflationYears);

    if (action == 1) {

        float priceFuture = itemPrice;

        // Add inflation rate for every year
        int i;
        for (i = 1; i <= inflationYears; i++) {
            priceFuture += (priceFuture * 0.045);
        }

        printf("Total price after %d years: %f\n", inflationYears, priceFuture);
    } else {

        float pricePast = itemPrice;
        
        // Deducts inflation rate for every months
        int i;
        for (i = 1; i <= inflationYears; i++) {
            pricePast -= (pricePast * 0.045);
        }
        
        printf("Total price %d years prior: %f\n", inflationYears, pricePast);
    }

    return 0;
}
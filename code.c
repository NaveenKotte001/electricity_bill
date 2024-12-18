#include <stdio.h>

int main() {
    int customerID;
    char name[50];
    float units, billAmount;

    // Input details
    printf("Enter Customer ID: ");
    scanf("%d", &customerID);
    printf("Enter Customer Name: ");
    scanf(" %[^\n]", name);
    printf("Enter Units Consumed: ");
    scanf("%f", &units);

    // Calculate bill amount based on slabs
    if (units <= 100) {
        billAmount = units * 1.5; // Rate for first 100 units
    } else if (units <= 300) {
        billAmount = (100 * 1.5) + (units - 100) * 2.0; // Rate for next 200 units
    } else {
        billAmount = (100 * 1.5) + (200 * 2.0) + (units - 300) * 3.0; // Rate above 300 units
    }

    // Minimum bill amount
    if (billAmount < 50) {
        billAmount = 50;
    }

    // Surcharge for high usage
    if (units > 300) {
        billAmount += billAmount * 0.15; // 15% surcharge
    }

    // Print bill details
    printf("\nElectricity Bill\n");
    printf("=====================\n");
    printf("Customer ID   : %d\n", customerID);
    printf("Customer Name : %s\n", name);
    printf("Units Consumed: %.2f\n", units);
    printf("Total Amount  : $%.2f\n", billAmount);

    return 0;
}

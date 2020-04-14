/**
 * cash.c
 *
 * Tim Haasnoot
 *
 * A code for calculatng the amount
  coins that are due.
 */

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //Prompt user for cash input and check if input is without dollar sign and positive
    float d;
    do
    {
        d = get_float("Change owed: ");
    }
    while (d <= 0);

    // Conversion to cents
    int c = round(d * 100);

    // Algorithm to calculate change using the largest coin possible
    int quarters = c / 25;
    int dimes = (c % 25) / 10;
    int nickels = ((c % 25) % 10) / 5;
    int pennies = ((c % 25) % 10) % 5;

    // Keep track of coins used, not coded but for reference only
    //printf("Quarters = %i\n", quarters);
    //printf("Dimes = %i\n", dimes);
    //printf("Nickels = %i\n", nickels);
    //printf("Pennies = %i\n", pennies);

    // Print the final number of coins
    printf("%d\n", quarters + dimes + nickels + pennies);
}

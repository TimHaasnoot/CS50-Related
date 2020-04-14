/**
 * mario.c
 *
 * Tim Haasnoot
 *
 * This C-program will build a pyramid with the height from the user's input ranging from 1-8.
 */


#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declaring of the variable height with a value of 0
    int height = 0;

    // Welcome user and explain what is asked
    printf("Please enter a height between 1 to 8 below.\n");

    // Do while loop to get user's input 1-8, otherwise asks again
    do
    {
        // Ask user for the height
        height = get_int("Height: ");
    }

    // Checks whether the input is between 1 and 8
    while (height < 1 || height > 8);

    // Pyramid building with user's input
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height - 1 - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}

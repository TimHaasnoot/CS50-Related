/**
 * recursion.c
 *
 * Tim Haasnoot
 *
 * Collatz implementation.
 */

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


int collatz(int n);

int main (void)
{
    int n = get_int("Please provide a positive integer: ");

    int answer = collatz(n);
    printf("The answer is %i.\n", answer);

}


int collatz(int n)
{
    // Base case

    if (n == 1)
    {
        return 0;
    }

    // Recursive case

    else if ((n % 2) == 0)
    {
        return 1 + collatz(n / 2);
    }
    else
    {
        return 1 + collatz(3 * n + 1);
    }

}

/**
 * hello.c
 *
 * Tim Haasnoot
 *
 * A code for printing out the name of the user.
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}

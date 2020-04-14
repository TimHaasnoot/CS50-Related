/**
 * triangle.c
 *
 * Tim Haasnoot
 *
 * A code that checks if a pyramid is valid.
 */

#include <cs50.h>
#include <stdio.h>

//declare function that checks if the triangle is correct
bool valid_triangle(float a, float b, float c);

int main(void)
{
    //get information on the sides of the triangle
    float a = get_float("What is side A of triangle?\n");
    float b = get_float("What is side B of triangle?\n");
    float c = get_float("What is side C of triangle?\n");

    //calling the function with user input
    bool answer = valid_triangle(a, b, c);

    //checks if the return value is true (1) or false (0)
    if (answer == 1)
    {
        printf("This is a correct triangle\n");
    }

    else
    {
        printf("This is not a triangle\n");
    }
}

//definition of the function
bool valid_triangle(float a, float b, float c)
{

    //checks if the triangle has positive sides
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }

    //checks if the two sides of the triangle are greater than the remaining side
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        return false;
    }

    return true;
}

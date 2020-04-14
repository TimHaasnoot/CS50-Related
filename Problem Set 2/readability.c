/**
 * readability.c
 *
 * Tim Haasnoot
 *
 * A code for calculating grade levels
  with input text.
 */

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// This program calculates the grade level according to the text that is acquired from the user.
// It uses a function called grade, from the famous Coleman-Liau index which takes two inputs.

// Function declaration
float grade(float L, float S);

// Main program start
int main(void)
{
    string text = get_string("Text: ");
    int letterscount = 0;
    int wordcount = 1;
    int sentencecount = 0;

// Various counters that use the string length
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letterscount++;
        }

        else if (text[i] == ' ')
        {
            wordcount++;
        }

        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentencecount++;
        }
    }

// Converting output to formula variables
    float L = letterscount * 100.0 / wordcount;
    float S = sentencecount * 100.0 / wordcount;

// Calling the function with the acquired formula variables
    float grade_no = grade(L, S);

// Printing out the grade level accordingly + rounded number
    if (grade_no < 16 && grade_no >= 0)
    {
        printf("Grade %i\n", (int) round(grade_no));
    }
    else if (grade_no >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

}

// Function Definition
float grade(float L, float S)
{
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}

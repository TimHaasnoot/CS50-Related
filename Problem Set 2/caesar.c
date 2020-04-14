/**
 * caesar.c
 *
 * Tim Haasnoot
 *
 * A code for encrypting text with a simple Caesar cipher.
 */

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Get the key to the cipher
int main(int argc, string argv[])
{
    string key = argv[1];

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else
    {
        // Convert the string to an integer
        int k = atoi(key) % 26;

        // Check that it is a valid key

        for (int l = 0; l < strlen(argv[1]); l++)
        {
            if ((!isdigit(argv[1][l])) == true)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        // Get the text to encrypt
        string plntxt = get_string("plaintext: ");

        if (plntxt != NULL)
        {

            printf("ciphertext: ");

            // Encrypt and print
            for (int i = 0, n = strlen(plntxt); i < n; i++)
            {
                int c = 0;

                // Check if text is upper case or lower case
                // If so, switch to alphabet number and encrypt
                if (isupper(plntxt[i]))
                {

                    c = (((int)plntxt[i] - 65 + k) % 26) + 65;
                    printf("%c", (char) c);
                }
                else if (islower(plntxt[i]))
                {

                    c = (((int)plntxt[i] - 97 + k) % 26) + 97;
                    printf("%c", (char) c);
                }
                else
                {
                    printf("%c", plntxt[i]);
                }
            }
            printf("\n");
            return 0;
        }
    }
}

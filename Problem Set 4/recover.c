/**
 * recover.c
 *
 * Tim Haasnoot
 *
 * A code for recovering JPEG files from memory after deletion.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{

    // Check command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover file name\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    //If the file does not exist, throw an error
    if (file == NULL)
    {
        printf("Could not open %s. File does not exist.\n", argv[1]);
        return 1;
    }

    //Creation of output file
    FILE *img = NULL;

    // Create buffer and filename arrays
    unsigned char buffer[512];
    char filename[8];

    //Set counter for filename
    int counter = 0;

    //Set flag (to indicate a found jpeg)
    bool flag;
    flag = false;
    

    // Read the file 512 bytes at the time
    while (fread(buffer, 1, 512, file) == 512)
    {
        
        // Make sure it is a jpeg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //Close current JPEG, so the next can be read
            if (flag == true)
            {
                fclose(img);
            }
            //Condition for found JPEG, so FLAG because we found a JPEG
            else
            {
                flag = true;
            }

            //Print the filename, open a new image file with that filename and increase the counter by 1
            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            counter++;
        }
        
        //Write recovered image
        if (flag == true)
        {
            fwrite(&buffer, 512, 1, img);
        }
    }
    
    //Close all files
    fclose(file);
    fclose(img);

    //Success
    return 0;
}
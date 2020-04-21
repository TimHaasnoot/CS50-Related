/**
 * helpers.c
 *
 * Tim Haasnoot
 *
 * A supporting code for filter.c through which you can edit photos with the filters below.
 */

#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float rgbtGrey;

    //Loop over each row
    for (int i = 0; i < height; i++)
    {
        //Loop over each pixel
        for (int j = 0; j < width; j++)
        {
            //Calculate the average and round it to nearest integer
            rgbtGrey = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.000);

            //Set new values
            image[i][j].rgbtRed = rgbtGrey;
            image[i][j].rgbtGreen = rgbtGrey;
            image[i][j].rgbtBlue = rgbtGrey;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    //Loop over each row
    for (int i = 0; i < height; i++)
    {
        //Loop over each pixel
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            //Set new values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];

    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width / 2; i++)
        {
            temp[0] = image[j][i].rgbtBlue;
            temp[1] = image[j][i].rgbtGreen;
            temp[2] = image[j][i].rgbtRed;

            // swap pixels with the ones on the opposite side of the picture and viceversa
            image[j][i].rgbtBlue = image[j][width - i - 1].rgbtBlue;
            image[j][i].rgbtGreen = image[j][width - i - 1].rgbtGreen;
            image[j][i].rgbtRed = image[j][width - i - 1].rgbtRed;

            image[j][width - i - 1].rgbtBlue = temp[0];
            image[j][width - i - 1].rgbtGreen = temp[1];
            image[j][width - i - 1].rgbtRed = temp[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int totalBlue;
    int totalGreen;
    int totalRed;
    float counter;

    //create a temporary table
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            totalBlue = 0;
            totalGreen = 0;
            totalRed = 0;
            counter = 0.00;

            //// Totals values of the pixel and 8 neighboring ones
            // Repeat 3 times
            for (int k = -1; k < 2; k++)
            {
                // Set boundaries (less than 0 || larger than height of the image)
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }

                //Repeat 3 times
                for (int h = -1; h < 2; h++)
                {
                    // Set boundaries (less than 0 || larger than width of the image)
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    totalBlue = totalBlue + image[j + k][i + h].rgbtBlue;
                    totalGreen = totalGreen + image[j + k][i + h].rgbtGreen;
                    totalRed = totalRed + image[j + k][i + h].rgbtRed;
                    counter++;
                }
            }

            // averages the total of the surrounding pixels
            temp[j][i].rgbtBlue = round(totalBlue / counter);
            temp[j][i].rgbtGreen = round(totalGreen / counter);
            temp[j][i].rgbtRed = round(totalRed / counter);
        }
    }

    //copies values from temporary table
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }

    return;
}

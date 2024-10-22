#include "helpers.h"
#include <math.h>
#include <stdio.h>

void swap(int *a, int *b);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through height of image
    for (int i = 0; i < height; i++)
    {
        // Loop through width of image
        for (int j = 0; j < width; j++)
        {
            // Get average of RGB values: sum divided 3
            float average = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);

            // Change hexidecimal values to achieve desired color
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Save color values to variables
            float originalRed = image[i][j].rgbtRed;
            float originalBlue = image[i][j].rgbtBlue;
            float originalGreen = image[i][j].rgbtGreen;

            // Calculate sepia values
            int sepiaRed = round((.393 * originalRed) + (.769 * originalGreen) + (.189 * originalBlue));
            int sepiaGreen = round((.349 * originalRed) + (.686 * originalGreen) + (.168 * originalBlue));
            int sepiaBlue = round((.272 * originalRed) + (.534 * originalGreen) + (.131 * originalBlue));

            // Cap max color value
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            // Assign new sepia values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Store value of image starting at location [0][0] in temp variable
            RGBTRIPLE temp = image[i][j];

            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Store value of image starting at location [0][0] in temp variable
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Iterates through entire image
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int sumRed, sumGreen, sumBlue;
                sumRed = sumGreen = sumBlue = 0;
                float counter = 0.0;

                // Finds neighboring pixels - on a grid where (x,y) is (0,0)
                for (int x = -1; x < 2; x++)
                {
                    for (int y = -1; y < 2; y++)
                    {
                        int outerX = i + x;
                        int outerY = j + y;

                        // If pixel is out of bounds, skip and continue loop
                        if (outerX < 0 || outerX > (height - 1) || outerY < 0 || outerY > (width - 1))
                        {
                            continue;
                        }

                        // Still inside neightboring pixel loop
                        // Add color values, counting # of squares
                        sumBlue += copy[outerX][outerY].rgbtBlue;
                        sumGreen += copy[outerX][outerY].rgbtGreen;
                        sumRed += copy[outerX][outerY].rgbtRed;

                        counter ++;
                    }

                    // Find average and assign to image location
                    image[i][j].rgbtRed = round(sumRed / counter);
                    image[i][j].rgbtBlue = round(sumBlue / counter);
                    image[i][j].rgbtGreen = round(sumGreen / counter);
                }
            }
        }
    }
    return;
}

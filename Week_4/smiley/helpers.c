#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // To Do: Change all black pixels to a color of your choosing

    // Loop through height of image
    for (int i = 0; i < height; i++)
    {
        // Loop through width of image
        for (int j = 0; j < width; j++)
         {
            // Check image struct to see if pixel located at x location (using height and width values) is 0 for all colors
            if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtBlue == 0x00 && image[i][j].rgbtGreen == 0x00)
            {
                // Change hexidecimal values to achieve desired color
                image[i][j].rgbtRed = 0x7A;
                image[i][j].rgbtBlue = 0xFF;
            }
        }
    }
}

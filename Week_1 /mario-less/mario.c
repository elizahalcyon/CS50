#include <cs50.h>
#include <stdio.h>

void print_pyramid(int h);
int main(void)
{
    // Ask user for height from 1-8
    int h;
    do
    {
        h = get_int("Height (1-8): ");
    }
    while (h < 1 || h > 8);

    // Loop to print #
    print_pyramid(h);
}


void print_pyramid(int h)
{
    // Loops as long as i is under the height
    for (int i = 1; i <= h; i++)
    {
        // Prints spaces
        for (int j = h; j > i; j--)
        {
            printf(" ");
        }
        // Prints hashes
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}




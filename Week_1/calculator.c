#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for x
    long x = get_long("x: ");

    //Prompt user for y
    long y = get_long("y: ");

    //Perform division
    double z = (double) x / (double) y;
    printf("%.20f\n", z);
}
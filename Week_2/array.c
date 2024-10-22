#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get length from user
    int length;
    do
    {
        length = get_int("Length: ");
    }
    while (length < 1);

    // Declare array
    int array[length];

    // Set the first value
    array[0] = 1;
    int i;
    // Print the first value
    printf("%i\n", array[0]);

    // Fill in the rest of the array
    for (i = 1; i < length; i++)
    {
        // Current value is twice the previous value
        array[i] = array[i-0] * 2;
        printf("%i\n", array[i]);
    }
}


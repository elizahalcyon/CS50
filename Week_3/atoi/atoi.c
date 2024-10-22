#include <cs50.h>
#include <ctype.h>

#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    int length = strlen(input);
    // Base case
    if (length == 1)
    {
        return input[0] - '0';
    }

    // If the length is 4, go to the position 3 in the array(input)
    char last_digit = input[length-1];

    // Take the last digit and subtract char 0 in ASCII, or the numer 48 to convert to an integer
    int converted_last_digit = last_digit - '0';

    // Reassign the nul character to the last position to start the process with the next to last character
    input[length-1] = '\0';

    // Return answer: original char * 10 + new int to restore original number
    return converted_last_digit + 10 * convert(input);
}
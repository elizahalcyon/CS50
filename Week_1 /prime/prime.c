#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    // Ask minimum
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    // Ask maximum
    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    // Print prime 'true'
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    if (number <= 1)
    {
        return false;
    }

    int i;
    for (i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

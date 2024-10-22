#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    // Prompt user for # of weeks, stores number as weeks
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    // Prompt user for hours per week
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    // Creates empty variable
    char output;
    //Loop to get either T or A which is saved as "output"
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    // Loop adds each element from hours
   int total = 0;
   for (int i = 0; i < weeks; i++)
   {
        total += hours[i];
   }
   if(output == 'T'){
        return (float) total;
   }
   return total / (float) weeks;
}
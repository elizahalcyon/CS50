#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Prompt user to agree
    char c = get_char("Do you agree? ");

    //Check whether agreed
    if (c == 'y' || c == 'Y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Not agreed.\n");
    }
}
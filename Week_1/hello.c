#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Ask for name
    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer);
}
#include <stdio.h>
#include <cs50.h>

int main(void)

{
    string name = get_string("Name: ");
    int age = get_int("Age: ");
    string phone = get_string("Phone Number: ");

    {
        printf("Name is %s. Age is %i.Phone number is %s.\n", name, age, phone);
    }
}

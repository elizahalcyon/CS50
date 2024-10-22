// Check that a password has at least one lowercase letter, uppercase letter, number and symbol

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    // Declare all elements false to start
    bool checklower = false;
    bool checkupper = false;
    bool checknumber = false;
    bool checksymbol = false;

    for (int i = 0, n = strlen(password); i < n; i++){

        // Use above loop to check each letter for specificiations
        if (islower(password[i])){
            checklower = true;
        }
        if (isupper(password[i])){
            checkupper = true;
        }
        if (isdigit(password[i])){
            checknumber = true;
        }
        if (!isalnum(password[i])){
            checksymbol = true;
        }
    if(checkupper == true && checklower == true && checknumber == true && checksymbol == true){
        return true;
        }
    }
    return false;
}


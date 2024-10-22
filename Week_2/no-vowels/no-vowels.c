#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string input);

int main(int argc, string argv[])
{
    // Loop if one command line argument not entered
    if (argc < 2)
    {
        printf("Enter one word\n");
        return 1;
    }
    string word = argv[1];

    string result = replace(word);

    printf("%s\n", result);
}

string replace(string input){
    string output = input;

        int i;

        for(i = 0; i < strlen(input); i++)
    {
            char c = (input[i]);

        switch (c)
        {
            case 'a':
                output[i] = '6';
                break;

            case 'e':
                output[i] = '3';
                break;

            case 'i':
                output[i] = '1';
                break;

            case 'o':
                output[i] = '0';
                break;

            default:
                output[i] = c;
                break;
        }
    }
    return output;
}
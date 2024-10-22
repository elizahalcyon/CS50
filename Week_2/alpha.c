#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string word = get_string("Word: ");
    int word_length = strlen(word);

    for (int i = 0; i < word_length - 1; i++)

    {
        // Check if it's NOT alphabetical
        if (word[i] > word[i + 1])
        {
            printf("No\n");
            // Exits program early instead of printing no no no etc
            return 0;
        }
    }

    printf("Yes\n");
    return 0;
}
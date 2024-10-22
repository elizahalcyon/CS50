#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_sentences(string text);
int main(void)
{
    string text = get_string("Text: ");
    int sentences = count_sentences(text);
    printf("%i\n", sentences);
}




int count_sentences(string text)

{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
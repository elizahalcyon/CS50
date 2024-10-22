#include <cs50.h>
#include <stdio.h>

// Define a new structure "candidate"
typedef struct
{
    string name;
    int votes;
} candidate;

// Call the function
candidate get_candidate(string prompt);

int main(void)
{
    candidate president = get_candidate("Enter a candidate: ");
    printf("%s\n", president.name);
    printf("%i\n", president.votes);
}

candidate get_candidate(string prompt)
{
    printf("%s\n", prompt);

    // Declare a new candidate
    candidate c;

    // Intialize the candidate's attributes
    c.name = get_string("Enter a name: ");
    c.votes = get_int("Enter votes: ");

    // Return the new candidate
    return c;
}
#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, string argv[])
{
    if (argc != 2) {
        printf("Improper usage.\n");
        return 1;
    }

    // Open file
    string filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("No such file found.\n");
        return 1;
    }

    uint8_t buffer[4];
    uint8_t signature[] = {37, 80, 68, 70};
    fread(buffer, 1, 4, file);
    // Can also close file here, right after reading it

    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != signature[i])
        {
            printf("Likely not a pdf.\n");
            // If you open a file, you have to close it
            fclose(file);
            return 0;
        }
    }
    printf("Likely a pdf!\n");
    // If you open a file, you have to close it
    fclose(file);
    return 0;
}
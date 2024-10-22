#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1; // same as *list = 1
    list[1] = 2; // same as *(list + 1)
    list [2] = 3;

    // Lots of code...

    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    // Copies original values to new location
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }

    tmp[3] = 4;

    free(list); // Frees the original address of list

    list = tmp;
    // Both list and tmp are pointers to chunks of memory; list variable should
    // point not at this chunk of three bytes but this chunk of four bytes

    for(int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list); // Frees the new chunk of memory with 4 bytes. Could also use free(tmp) but this is better design
    return 0;
}

/* int list[3];

    list[0] = 1;
    list[1] = 2;
    list [2] = 3;

    for(int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    } */
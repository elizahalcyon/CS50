#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    // Need to use & to tell swap the addresses of x and y
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b)
{
    /* Need * to change actual values at the address. Without, it doesn't work because a and b are copies,
     within the scope of the function: x and y themselves never change. */
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
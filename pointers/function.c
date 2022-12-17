#include <stdio.h>

// function returning a pointer
int * change (int *b)
{
    *b = 30;
    printf("value inside fn %d\n", *b);
    return b;
}


#include <stdio.h>
#include "function.c"

int main()
{
    int a = 10;
    int *ptr;
    ptr = change(&a);
    printf("ptr val %d", *ptr);

    return 0;
}

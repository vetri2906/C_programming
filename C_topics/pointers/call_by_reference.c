#include <stdio.h>

// function returning a pointer
int * change (int *b)
{
    *b = 30;  // value of a is changed as value is written to the address
    printf("value inside fn %d\n", *b);
    return b;
}
int main()
{
    int a = 10;
    int *ptr;
    ptr = change(&a); // call by reference, addess of variable a is passed here
    // basically ptr is pointing to variable a
    printf("ptr val %d", *ptr); // value of a

    return 0;
}

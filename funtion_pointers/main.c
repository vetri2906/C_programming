/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include "typedef_fn_ptr.c"
void sum (int a, int b)
{
    int c = (a+b);
    printf("%d\n",c);
}

// parameters to the fn. pointer can be passed only during fn. call - which is below
int function (void (*fun_ptr)(int, int), int a, int b)
{
//Since parameters can be passed only here, int a and int b are declared above, so that - 
// continued in main.
   fun_ptr(a,b);
}

int main()
{
    // so that sum of any two numbers can be performed.
    // similarly subtraction of any two numbers can be done.
function(sum, 5, 10);

typedef_fnptr();
    return 0;
}

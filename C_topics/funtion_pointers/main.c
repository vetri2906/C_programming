/******************************************************************************



*******************************************************************************/
#include <stdio.h>
 
void sum (int a, int b)
{
    int c = (a+b);
    printf("sum of a and b is : %d\n",c);
}
/*
  parameters - fn.pointer, int, int
*/
int function (void (*fun_ptr)(int, int), int a, int b)
{
   fun_ptr(a,b); // whatever fn address is passed as parameter will be called here.
}

int main()
{
    function(sum, 5, 10);   // sum of any two numbers can be derived. similarly subtraction of any two numbers can be done.        
    return 0;
}

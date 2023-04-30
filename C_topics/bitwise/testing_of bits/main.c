/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t num1;
   printf("enter a number\n");
   scanf("%d", &num1);
   if (num1 & 1) // if lsb == 1, condition becomes true
   {
    printf("number is odd");
   }
   else if ((num1 & 1) ==0) // if lsb == 0 condition is false
   {
   printf ("number is even");
   }   
return 0;
}

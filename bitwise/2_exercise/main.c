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
    int32_t num1, num2;
   printf("enter two numbers\n");
   scanf("%d %d", &num1, &num2);
   printf("bitwise and %d \n", (num1 & num2));
   printf("bitwise or %d \n", (num1 | num2));
   printf("bitwise not %d \n", (~num1));
   printf("bitwise xor %d \n", (num1 ^ num2));
return 0;
}

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
// casting float to char    not possible
// casting float to char *   not possible
// casting float to int *  garbage value

int main()
{
    float a = 20;
    char b = 's';
    b = (char) a;
    
    char *d;
    float c = 50;
    d = (char*) &c;
  
    int *e;
    float f = 50;
    e = (int*) &f;  
    
    printf("%c\n",b);
    printf("%c",*d);
    printf("%d",*e);

    return 0;
}

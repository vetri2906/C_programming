/******************************************************************************

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

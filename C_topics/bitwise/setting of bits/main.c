
/*set 4th and 7th bit to a given number*/

#include <stdio.h>
#include <stdint.h>
int main()
{
 int32_t num1;
 printf("enter a number: \n");
 scanf("%d", &num1);

printf("decimal format : %d", (num1 | 0b10010000));
printf("\nhex format %x", (num1 | 0b10010000));
return 0;
}

 //How to check if 4th bit is set in C? 
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void main()
{
 int num;
 int bit_position;
 
 printf("enter a number and bit position to check\n");
 scanf("%d", &num);
 scanf("%d", &bit_position);

 int c = (num & (1<<bit_position));
 printf("%d", (num & (1<<bit_position)));

}
//problem variables are declared as uint16 and passed inside scanf 
//with %d as format specifier
// use int instead of uint16_t

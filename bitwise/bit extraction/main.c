
/*save bits 14: 9 in a separate variable*/

#include <stdio.h>
#include <stdint.h>
int main()
{
 uint16_t num1 = 0xb410;
 uint8_t output;

output = (uint8_t) ((num1 >> 9) & (~(0xffc0)));
printf("%x", output);
return 0;
}

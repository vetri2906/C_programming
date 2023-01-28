
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

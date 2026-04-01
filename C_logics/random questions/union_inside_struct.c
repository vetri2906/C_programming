#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef union common_mem
{
  struct 
  {
    bool b;
    uint8_t a;
  }s1;
  uint16_t b;
} common_mem_t;


int main()
{
  common_mem_t memory;
  memory.b = 0x1234;
  printf("%x",memory.s1.b);
  return 0;
}

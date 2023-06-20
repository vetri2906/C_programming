// factorial
#include <stdio.h>
void factorial_forloop(void);
void factorial_whileloop(void);

int main() {
  factorial_forloop();
  factorial_whileloop();
  return 0;
}

void factorial_forloop(void)
{
  int range;
  int fact;
  printf("enter range for factorial:\t");
  scanf("%d",&range);
  fact  = range;
  for (int i = range; i >1; i--)
  {
    fact *= (--range);
  }
  printf("factorial of the given range is : %d\n", fact);
}

void factorial_whileloop(void)
{
  int range;
  int fact;
  printf("enter the factorial range:\t");
  scanf("%d",&range);
  fact = range;
  while(range>1)
  {
    fact*=(range-1);
    --range;
  }
  printf("factorial of the given range is %d", fact);
}
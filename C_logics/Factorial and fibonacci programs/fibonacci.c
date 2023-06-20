// fibonacci
#include <stdio.h>
void fibonacci_forloop(void);
void fibonacci_whileloop(void);

int main() {
  fibonacci_forloop();
  fibonacci_whileloop();
  return 0;
}

void fibonacci_forloop(void)
{
  int range = 0;
  int fib1 = 0;
  int fib2 = 1;
  int fib3 = 0;
  
  printf("enter the range\t");
  scanf("%d",&range);
  printf("%d\t%d\t",fib1,fib2);
  if ((range != 0) && (range != 1))
  {
    for(int i = 2; i <range; i++)
    {
      fib3 = fib1 + fib2;
      printf("%d\t",fib3);
      fib1 = fib2;
      fib2 = fib3;
    }
  }
}

void fibonacci_whileloop(void)
{
  int fib1 = 0;
  int fib2 = 1;
  int range, fib3;
  int count = 2;
  printf("\nenter the range of fibonacci series:\t");
  scanf("%d",&range);
  printf("%d\t%d\t",fib1, fib2);
  while(count < range)
  {
    fib3 = fib2 + fib1;
    printf("%d\t",fib3);
    fib1 = fib2;
    fib2 = fib3;
    count++;
  }
}
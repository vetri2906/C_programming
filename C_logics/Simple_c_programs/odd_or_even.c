// odd or even

#include <stdio.h>

int main() {
  int a;
  printf("enter a number\n");
  scanf("%d", &a);            // do not use /n after %d
  if((a%2) == 0) {
    printf("number is even");
  } else {
    printf("the number is odd");
  }
}
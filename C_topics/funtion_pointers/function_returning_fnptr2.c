
#include <stdio.h>

typedef int myfunction(int a, int b);

int adder(int a, int b) {
    return a + b;
}

int minus(int a, int b) {
    return a - b;
}

int callerfunction(myfunction *p, int a, int b) {
    return p(a, b);
}

int function1(void) {
    int result;
    
    result = callerfunction(&adder, 15, 20);
    printf("Add Result: %d\n", result);
    
    result = callerfunction(&minus, 15, 20);
    printf("Substract Result: %d\n", result);
    
    return 0;
}

int main()
{
    function1();   
    return 0;
}
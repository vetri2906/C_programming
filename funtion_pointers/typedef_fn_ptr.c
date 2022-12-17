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

int typedef_fnptr(void) {
    int result;
    
    result = callerfunction(&adder, 15, 20);
    printf("Add Result: %d\n", result);
    
    result = callerfunction(&minus, 15, 20);
    printf("Substract Result: %d\n", result);
    
    return 0;
}












// C program for the above approach
#include <stdio.h>
 
// This defines a type for
// function prototypes

typedef int (*ptr)(int*);

typedef ptr (*pm)();
 

int fun1(int* y)
{

    printf("geeks!!\n");

    return *y + 10;
}
 
// fun() is a function with
// return type ptr
ptr fun()
{

    printf("Hello ");
 

    // or return fun1;

    /* or

     int(*pt)(int*)=fun1;

     return pt

  */

    return &fun1;
}
 
// Driver code

int fn_ptr2()
{

    int a = 10;

    pm u = fun;
 

    /*

    Above line assigns 'u' which is 

    of type 'pm' to an array of size 

    1 which has function pointers as 

    its elements and these function 

    pointers in turn return other 

    function pointer which points to 

    other functions.
 

    Now this 'p' array contains a function 

    pointer 'u' which points to fun() and 

    this fun() returns another function

    pointer which points to fun1().

  */

    int (*(*p[1])())(int*) = { u };
 
//to explain the above line - (*p[1])() is a fn pointer which has function pointer as
// return type. Now the top layer fn pointer - (*(*p[1])())(int*) has int as return type

    printf("%d", (*p[0]())(&a));
}










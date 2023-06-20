/******************************************************************************



*******************************************************************************/
#include <stdio.h>

typedef int (*ptr)(int*);// This defines a type for function prototypes
typedef ptr (*pm)(void); //typedef a fn pointer which returns a function pointer
 
int fun1(int* y)
{
    printf("world !!!\n");
    return *y + 10;
}
 
/*fun(void) is a function with return type function ptr*/
ptr fun(void)
{
    printf("Hello ");
    return &fun1;
    // or return fun1;
    /* or int(*pt)(int*)=fun1;
     return pt
  */
}
 
int fn_ptr2()
{
    int a = 10;
    pm u = fun; // u is a function pointer variable that returns fun. pointer
/* Above line assigns 'u' which is of type 'pm' to an array of size 1 which has function pointers as 
    its elements and these function pointers in turn return other function pointer which points to other functions.
    Now this 'p' array contains a function pointer 'u' which points to fun() and this fun() returns another function
    pointer which points to fun1().*/

    int (*(*p[1])())(int*) = { u }; // double pointer
    printf("%d", (*p[0]())(&a));
}

int main()
{
    fn_ptr2();
    return 0;
}

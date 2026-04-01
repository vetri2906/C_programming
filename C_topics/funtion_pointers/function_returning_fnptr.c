/*In this file we have a function EventSelect that returns address of some other function
this address returned is stored in a function pointer and used to print some output*/

#include <stdio.h>

/*typedefs*/
int (*Ptr)(int,int);

/*function definitions*/
int sum(int x, int y) { 
    return (x+y); 
}
 
int Difference(int x, int y) { 
    return (x-y); 
 }
 
/*function returning function pointer
This can also be very useful in writing functions that return function pointers such as 
follows*/
int (*EventSelect(const char code)) (int, int) { 
 if (code == '+') return &sum; 
 if (code == '-') return &Difference; 
} 
/* The above function takes a char as an argument and returns a function pointer of type Ptr 
        (as defined above) based on if the char is + or – 
        Now we can simplify the EventSelect definition as follows. 
Ptr EventSelect(const char code) { 
 if (code == '+') return &sum; 
 if (code == '-') return &Difference; 
} 
*/
int main ( ) { 
 int (*ptr)(int,int); /* or: Ptr fp; if you have a typedef */ 
 ptr = EventSelect('+');  /* this means ptr = sum */
 printf( "return value is %d \n", ptr(2,4)); 
} 

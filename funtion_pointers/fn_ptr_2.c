
#include <stdio.h>


typedef int (*Ptr)(int,int); 


int sum(int x, int y) { 
 return (x+y); 
 }
 
 int Difference(int x, int y) { 
 return (x-y); 
 }
Ptr fp = sum; 
// This can also be very useful in writing functions that return function pointers such as 
// follows. 
int (*Convert(const char code)) (int, int) { 
 if (code == '+') return &sum; 
 if (code == '-') return &Difference; 
} 
// The above function takes a char as an argument and returns a function pointer of type Ptr 
// (as defined above) based on if the char is + or – 
// Now we can simplify the Convert definition as follows. 
// Ptr Convert(const char code) { 
//  if (code == '+') return &sum; 
//  if (code == '-') return &Difference; 
// } 
// Use the Convert function as follows 
int main ( ) { 
 int (*ptr)(int,int); /* or: Ptr ptr; if you have a typedef */ 
 ptr = Convert('+'); 
 printf( "%d \n", ptr(2,4)); 
} 

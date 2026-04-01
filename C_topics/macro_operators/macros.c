#include <stdio.h>
#include <stdint.h>

/*stringize # + token paster ##*/
#define tokenpaster(n) printf ("token" #n " = %d\n", n##token);\  
                        printf("%d",name##n);
#define ENUM(name) typedef uint8_t name; enum name##_enum
#define CUSTOM_ENUM(name, type) typedef type name; enum name##_enum

/* To understand ENUM(name) - refer
https://www.tutorialspoint.com/cprogramming/c_preprocessors.htm
The Token Pasting (##) Operator
The Stringize (#) Operator
Parameterized Macros
*/

int main()
{
    int atoken = 40;
    int namea = 30;
    tokenpaster(a);
    /*
    ENUM(name)  working explained below - 2 lines
    typedef uint8_t name; 
    enum name_enum
    */
    return 0;
}

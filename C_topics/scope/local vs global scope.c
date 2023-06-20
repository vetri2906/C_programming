// a block is basically an open and closed curly bracket of code inside a function
//function example is main
// program is a c file or bunch of c files

#include <stdio.h>

int i =0 ;  // global variable

int main()
{
    int i = 15;
    for (int i = 0; i <10; ++i)     // this i belongs to the block alone
    { //block starts here
      printf("%d",i);
    }
    printf("\n outside loop  :  %d",i); /* this i is different  --> access the 
                                           local i first that is declared inside main(closer one first)
                                           before going to global i = 0;*/
    return 0;
}

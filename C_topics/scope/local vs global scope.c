// a block is basically an open and closed curly bracket of code inside a function
//function example is main
// program is the c file or bunch of c files

#include <stdio.h>

    int i =0 ;


int main()
{
    int i = 15;
  //block starts here
    for (int i = 0; i <10; i++)     // this i belongs to the block alone
    {
            printf("%d",i);

    }
    printf("\n outside loop  :  %d",i);    // this i is different  -- access the local i first (closer one first)
                                                // before going to global i = 0;
    return 0;
}

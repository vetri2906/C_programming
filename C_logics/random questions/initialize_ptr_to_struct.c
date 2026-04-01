/******************************************************************************

initialize a structure to 0 in one line using pointer to struct

*******************************************************************************/
#include <stdio.h>

typedef struct student 
{
    int a;
    float b;
} student_t;

int main()
{
    student_t st_var = {2,3.0}; // struct initialized to a value
    student_t *st_ptr = &st_var;
    printf("val before initialize :\n%d\n",st_ptr->a);
    printf("%f\n",st_ptr->b);
    *st_ptr = (student_t){0};  // struct assigned to 0 in one line using pointers
    printf("val after initialize :\n%d\n",st_ptr->a);
    printf("%f",st_ptr->b);
    return 0;
}


#include <stdio.h>
/* typedefs */
typedef struct
{
  char a;
  double x;
  double y;
  int z;
} Student_t;

typedef struct
{
  double x;
  double y;
  double z;
} Employee_t;

/*variables*/
Employee_t employee;
Employee_t test;
Student_t student;

int main ()
{
  test.x = 30;
  employee = test;        
  // student = test; // "incompatible type"
  printf("%f", employee.x);
  return 0;
}


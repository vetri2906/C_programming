
#include <stdio.h>

typedef struct
{
  double x;
  double y;
  double z;
} Student_t;


typedef struct
{
  double x;
  double y;
  double z;
} Employee_t;


Employee_t employee;
Employee_t test;
Student_t student;

int main ()
{
    test.x = 30;

  employee = test;	// "incompatible type"

  printf ("%f", employee.x);

  return 0;
}


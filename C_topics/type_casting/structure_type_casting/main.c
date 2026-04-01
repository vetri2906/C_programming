
#include <stdio.h>

typedef struct
{
  char x;
  int y;
  char*z;
} Student_t;

typedef struct
{
  float x;
  char y;
} Employee_t;


Employee_t employee;
Employee_t test;
Student_t student;

int main ()
{
// test.x = 30;
student.x = 'c';
student.y = 70;
student.z = "string";
// employee = test;	// "incompatible type"
// but this is not in the specs and therefore the behaviour depends on the compiler
Employee_t *employee1 = (Employee_t*)&student;
// employee1 is a pointer variable of type Employee_t. Employee_t has two elements.
// But even though Employee_t has two elements, It can hold address of Student_t type variable that 
// has three elements

//  printf("%c\n", employee1->y);
 printf("%f\n", employee1->x);
 printf("%c", student.x);

  return 0;
}

// void AccelerationToVector( Employee_t* from, Student_t* to )
// {
//      to->x = from->x;
//      to->y = from->y;
//      to->z = from->z;
// }

// static inline Student_t AccelerationToVector1(Employee_t In)
// {
//     return (Student_t){In.x, In.y, In.z};
// }
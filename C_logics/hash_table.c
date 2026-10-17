
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define TABLE_SIZE (10)

struct details
{
    char name[20];
    int age;
    int weight;
};

struct details * people[TABLE_SIZE] = {0};

int hash(char*name)
{
    int hash_value;
    int length = strlen(name);
    for (int i = 0; i< length; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

struct details * hash_insert(struct details * x)
{
    int index = hash(x->name);
    int try;
    // if(people[index] != NULL) // occupied
    for(int i = 0 ; i < TABLE_SIZE; i++)
    {
        try = (index +i) % TABLE_SIZE;
        // search for null and insert there
       if(people[try] == NULL) 
       {
           people[try] = x;
           return people[try];
       }
    }
    
    // table is full - inform caller
    return NULL;
    
    // people[index] = x;
}

struct details * hash_lookup(char *x)
{
  int index = hash(x);
  if(people[index] == NULL) return NULL; // never inserted
  int try;
    for(int i = 0 ; i < TABLE_SIZE; i++)
    {
        try = (index +i) % TABLE_SIZE;
        // search for null and insert there
       if((people[try] != NULL) && (strcmp(x,people[try]->name) == 0)) 
       {
            return people[index];
       }
    }
    return NULL;
}

void print_table(void)
{
    printf("start\n");  
    for(int i = 0; i<TABLE_SIZE; i++)
    {
        if(people[i] ==NULL)
        {
            printf("%d---------\n", i);  
        }
        else
        {
            printf("%d. %s\n",i, people[i]->name);  
        }
    }
    printf("end\n");  
}

int main()
{
    print_table();
    struct details jane   = {.name = "jane", .age = 26, .weight = 55};
    struct details justin = {.name = "justin", .age = 20, .weight = 60};
    struct details vetri  = {.name = "vetri", .age = 30,.weight = 63};
    struct details jerry  = {.name = "jerry", .age = 35,.weight = 63};
    struct details fevi   = {.name = "fevi", .age = 38,.weight = 63};
    struct details stick  = {.name = "stick", .age = 40,.weight = 63};

    hash_insert(&jane);
    hash_insert(&justin);
    hash_insert(&vetri);
    hash_insert(&jerry);
    hash_insert(&fevi);
    hash_insert(&stick);
    print_table();
    struct details *vetri_looked = hash_lookup("vetri");
    printf("vetri age is : %d\n", vetri_looked->age);
    
    struct details *jerry_looked = hash_lookup("jerry");
    printf("jerry age is : %d\n", jerry_looked->age);
    
    struct details *jane_looked = hash_lookup("jane");
    printf("jane age is : %d\n", jane_looked->age);
    
    struct details *justin_looked = hash_lookup("justin");
    printf("justin age is : %d\n", justin_looked->age);
    
    return 0;
}

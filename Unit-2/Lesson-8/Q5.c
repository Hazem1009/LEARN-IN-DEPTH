#include <stdio.h>


typedef struct
{
    char name[50];
    long id;
} Employee;

int main()
{
    //a pointer to an array which contents are pointer to structure.
    Employee* (*ptr)[5];
    Employee* employees_ptrs[5];
    ptr=&employees_ptrs;
    Employee employees[5]= { {"John",1000},{"David",1001},{"Alex",1002},{"Chris",1003},{"James",1004} };
    for (int i = 0; i < 5; i++)
    {
        employees_ptrs[i]=&employees[i];
    }
    printf("Employee name: %s\n", (*ptr)[2]->name);
    printf("Employee id: %ld\n", (*ptr)[2]->id);
    

    return 0;
}
#include <stdio.h>

typedef struct 
{
    char name[50];
    int roll;
    float marks;
}Student;

int main()
{
    Student s1;
    printf("Enter information of students:\n");
    printf("Enter name: ");
    scanf("%s", s1.name);
    printf("Enter roll number: ");
    scanf("%d", &s1.roll);
    printf("Enter marks: ");
    scanf("%f", &s1.marks);
    printf("Displaying Information:\n");
    printf("Name: %s\n", s1.name);
    printf("Roll: %d\n", s1.roll);
    printf("Marks: %.2f\n", s1.marks);
    return 0;
}
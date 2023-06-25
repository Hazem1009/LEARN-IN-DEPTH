#include <stdio.h>

typedef struct 
{
    char name[50];
    int roll;
    float marks;
}Student;

int main()
{
    Student studentArray[10];
    printf("Enter information of students:\n\n");
    for(int i=0;i<10;i++)
    {
     
        printf("For roll number %d\n", i+1);
        printf("Enter name: ");
        scanf("%s", studentArray[i].name);
        printf("Enter marks: ");
        scanf("%f", &studentArray[i].marks);
    }
    printf("Displaying Information:\n");
    for(int i=0;i<10;i++)
    {
        printf("Information for roll number %d\n", i+1);
        printf("Name: %s\n", studentArray[i].name);
        printf("Marks: %.2f\n", studentArray[i].marks);
    }
}
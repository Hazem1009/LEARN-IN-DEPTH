#ifndef LL_H
#define LL_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int day;
    int month;
    int year;
}Date;
/*Student entry in database*/
typedef struct 
{
    int ID;
    char name[40];
    float height;
}Student;

typedef struct Node
{
    Student data;
    struct Node* next;
} node;


void AddStudent();

void RemoveStudent( int ID);

node* FindStudentByID( int ID);

void ViewStudents();

int GetListLength_Iterative();

int GetListLength_Recursive(node* head);

node* GetNthNode_from_End(int n);




void DeleteAll();

void Print_Student_Content(Student* data);

node* FindNthNode(int n);






#endif // LL_H
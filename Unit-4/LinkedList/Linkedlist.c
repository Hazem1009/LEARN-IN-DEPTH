#include "Linkedlist.h"
extern node* head;
void Print_Student_Content(Student* data)
{
    printf("-----------------Displaying Entry-----------------\n");
    printf("Student ID:%d \n",data->ID);
    printf("Student Name:%s \n",data->name);
    printf("Student Height:%f \n",data->height);
    printf("-----------------End of Entry-----------------\n");
    
}

void Fill_Entry(Student* data)
{
    printf("\nEnter ID:");
    scanf("%d",&(data->ID));
    printf("\nEnter Student Name:");
    scanf("%s",&(data->name));
    fflush(stdin);
    fflush(stdout);
    printf("\nEnter Student Height");
    scanf("%f",&(data->height));
    return ;
}
void AddStudent()
{
    if(head==NULL)
    {
        node * temp = (node*)malloc(sizeof(node));
        Fill_Entry(&(temp->data));
        temp->next=NULL;
        head=temp;
    }
    else
    {
        node * temp = head;
        while(temp->next)
        {
            temp=temp->next;
        }
        node * newStudent = (node*)malloc(sizeof(node));
        Fill_Entry(&(newStudent->data));
        newStudent->next=NULL;
        temp->next=newStudent;
    }
}

void RemoveStudent(int ID)
{
    node * temp= head;
    node * prev=NULL;
    if(head==NULL)
    {
        printf("Head is null , cant loop!");
    }

    while(temp)
    {
        if(temp->data.ID == ID)
        {
            if(temp==head)
            {
                head=temp->next;
                free(temp);
                return;
            }
            else
            {
                prev->next = temp->next;
                temp->next =NULL;
                free(temp);
                return ;
            }

        }
        prev=temp;
        temp=temp->next;
    }
}

node* FindStudentByID(int ID)
{
    node* temp=head;
    while(temp)
    {
        if(temp->data.ID == ID)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}
void ViewStudents()
{
    if(head==NULL)
    {
        printf("Data base is empty!");
        return;
    }

    node * temp = head;
    while(temp)
    {
       Print_Student_Content(&(temp->data));
        temp=temp->next;
    }
}

void DeleteAll()
{
    node * toDelete = head;

    if(head==NULL)
    {
        printf("Can't Delete All,Data base is empty");
    }

    while(toDelete)
    {
        node* temp =toDelete;
        toDelete = toDelete->next;
        free(temp);
    }
    //To avoid usage of non reserved memory any more.
    head=NULL;
}

/*Find Nth node*/
node* FindNthNode(int n)
{

    node * temp = head;
    int i=0;
    while(temp)
    {
        if(i==n)
        {
            return temp;
        }
        temp=temp->next;
        i++;
    }
    return NULL;
}


int GetListLength_Iterative()
{
    node * temp = head;
    int count=0;
    while(temp)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

int GetListLength_Recursive(node * head)
{
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        return 1+GetListLength_Recursive(head->next);
    }
}

node* GetNthNode_from_End(int n)
{
    node* hare = head;
    node* tortoise = head;
    int i=0;
    while(i<n)
    {
        hare=hare->next;
        i++;
    }
    while(hare)
    {
        hare=hare->next;
        tortoise=tortoise->next;
    }
    if(tortoise==NULL)
    {
        printf("N is greater than list length");
        return NULL;
    }
    return tortoise;
}

node* FindMiddleNode()
{
    node* hare = head;
    node* tortoise = head;
    while(hare && hare->next)
    {
        hare=hare->next->next;
        tortoise=tortoise->next;
    }
    return tortoise;
}

uint8_t IsListCyclic()
{
    node* hare = head;
    node* tortoise = head;
    while(hare && hare->next)
    {
        hare=hare->next->next;
        tortoise=tortoise->next;
        if(hare==tortoise)
        {
            return 1;
        }
    }
    return 0;
}

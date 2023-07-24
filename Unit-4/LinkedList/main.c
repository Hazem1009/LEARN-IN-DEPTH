#include "LinkedList.h" 
node * head = NULL;


void Menu_Choices()
{
    printf("\n-----------------Menu-----------------\n");
    printf("1-Add Student\n");
    printf("2-Remove Student\n");
    printf("3-View Students\n");
    printf("4-Find Student\n");
    printf("5-Delete All\n");
    printf("6-Nth Node\n");
    printf("7-Length of List Iterative\n");
    printf("8-Length of List Recursive\n");
    printf("9-Exit\n");
    printf("Enter your choice:");
    printf("\n-----------------End of Menu-----------------\n");
}

int main()
{
    int choice=0;
    int ID=0;
    while(1)
    {
        Menu_Choices();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                AddStudent();
                break;
            case 2:
                printf("Enter ID to remove:");
                scanf("%d",&ID);
                RemoveStudent(ID);
                break;
            case 3:
                ViewStudents();
                break;
            case 4:
                printf("Enter ID to find:");
                scanf("%d",&ID);
                node * temp = FindStudentByID(ID);
                if(temp)
                {
                    Print_Student_Content(&(temp->data));
                }
                else
                {
                    printf("Student not found!");
                }
                break;
            case 5:
                DeleteAll();
                break;
            case 6:
                int n;
                printf("Enter N:");
                scanf("%d",&n);
                
                Print_Student_Content(&((FindNthNode(n))->data));
                break;
            case 7:
                printf("Length of list is %d",GetListLength_Iterative());
                break;
            case 8:
                printf("Length of list is %d",GetListLength_Recursive(head));
                break;
            default:
                printf("Invalid choice!");
                break;
        }
    }
    return 0;   
}
#include <stdio.h>
#include "stack.h"


int main(void)
{
    Stack_t Buffer;
    Stack_Data_Type arr[5];
    Stack_Status status;
    uint8_t item;
    status=Stack_init(&Buffer,arr,5);
    printf("-----------------Stack Test-----------------\n");

    if(status==STACK_NO_ERROR)
    {
        printf("Stack initialized successfully\n");
    }
    else
    {
        printf("Stack initialization failed\n");
        return 0;
    }

    printf("------------Pushing Test------------\n");

    for(int i=0;i<=6;i++)
    {
        if(Stack_Push(&Buffer,i)==STACK_NO_ERROR)
        {
            printf("Pushed %d successfully\n",i);
        }
        else
        {
            printf("Pushing %d failed\n",i);
        }
    }

    printf("------------Popping Test------------\n");
    for(int i=0;i<=6;i++)
    {
        if(Stack_Pop(&Buffer,&item)==STACK_NO_ERROR)
        {
            printf("Popped %d successfully\n",item);
        }
        else
        {
            printf("Popping failed\n");
        }
    }


    return 0;
}
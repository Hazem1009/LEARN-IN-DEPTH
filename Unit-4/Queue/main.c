#include "Queue.h"
#include <stdio.h>
void printArray(Queue_Item* arr,uint32_t size)
{
    printf("Array content is: ");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    Queue_Item item;
    Queue_Item arr[5];
    Queue_t Buffer;
    printf("------------------------Initializing the queue------------------------\n");
    Queue_init(&Buffer,arr,5);
    printf("------------------------Enqueuing 6 items------------------------\n");
    Queue_enqueue(&Buffer,1);
    Queue_enqueue(&Buffer,2);
    Queue_enqueue(&Buffer,3);
    Queue_enqueue(&Buffer,4);
    Queue_enqueue(&Buffer,5);
    Queue_enqueue(&Buffer,6);
    printf("------------------------Dequeuing 2 items------------------------\n");
    printArray(arr,5);
    Queue_dequeue(&Buffer,&item);
    Queue_dequeue(&Buffer,&item);
    Queue_dequeue(&Buffer,&item);
    Queue_Print(&Buffer);
    printf("------------------------Enqueuing 2 items------------------------\n");
    Queue_enqueue(&Buffer,6);
    Queue_enqueue(&Buffer,7);
    Queue_enqueue(&Buffer,8);
    printArray(arr,5);  
    Queue_dequeue(&Buffer,&item);
    Queue_enqueue(&Buffer,9);
    printArray(arr,5);

    printf("------------------------Printing the queue------------------------\n");

    Queue_Print(&Buffer);

    printf("------------------------Printing Array content------------------------\n");
    printArray(arr,5);

    return 0;
}
#include "Queue.h"
#include <stdio.h>
Queue_Status Queue_init(Queue_t* Buffer,Queue_Item* arr,uint32_t size)
{
    if(arr == NULL)
    {
        Buffer=NULL;
        Buffer->base=NULL;
        Buffer->head=NULL;
        Buffer->tail=NULL;
        Buffer->count=0;
        Buffer->size=0;
        return QUEUE_NULL;
    }
    Buffer->base=arr;
    Buffer->head=arr;
    Buffer->tail=arr;
    Buffer->count=0;
    Buffer->size=size;
    return QUEUE_NO_ERROR;  
}

Queue_Status Queue_enqueue(Queue_t* Buffer,Queue_Item item)
{
    if(Buffer==NULL||Buffer->base==NULL||Buffer->head==NULL||Buffer->tail==NULL)
    {
        return QUEUE_NULL;
    }
    // check if the queue is full
    if(Queue_is_full(Buffer)==QUEUE_FULL)
    {
        printf("Queue is full,can't Enqueue\n");
        return QUEUE_FULL;
    }

    //insert the item
     *(Buffer->head)=item;
    printf("Enqueued item is %d\n",*(Buffer->head));

    //increment the count
    Buffer->count++;
    
    //circulate the head pointer
    if(Buffer->head >= Buffer->base + (Buffer->size-1))
    {
        Buffer->head = Buffer->base;
    }
    else
    {
        Buffer->head++;
    }
   
    return QUEUE_NO_ERROR;
}
Queue_Status Queue_dequeue(Queue_t* Buffer,Queue_Item* item)
{
    if(Buffer==NULL||Buffer->base==NULL||Buffer->head==NULL||Buffer->tail==NULL)
    {
        return QUEUE_NULL;
    }
    if(Buffer->count==0)
    {
        printf("Queue is empty\n");
        return QUEUE_EMPTY;
    }

    //dequeue the item
    *item=*(Buffer->tail);
    printf("Dequeued item is %d\n",*item);
    Buffer->count--;
    //circulate the tail pointer
    if(Buffer->tail == Buffer->base + (Buffer->size))
    {
        Buffer->tail = Buffer->base;
    }
    else
    {
        Buffer->tail++;
    }
   
    return QUEUE_NO_ERROR;
}

Queue_Status Queue_is_full(Queue_t* Buffer)
{
    if(Buffer==NULL||Buffer->base==NULL||Buffer->head==NULL||Buffer->tail==NULL)
    {
        return QUEUE_NULL;
    }
    if(Buffer->count>=Buffer->size)
    {
        return QUEUE_FULL;
    }

    return QUEUE_NOT_FULL;
}

void Queue_Print(Queue_t*Buff)
{
    if(Buff==NULL||Buff->base==NULL||Buff->head==NULL||Buff->tail==NULL)
    {
        return;
    }

    if(Buff->count==0)
    {
        printf("Queue is empty\n");
        return;
    }
    //1 2 3 4 5
    // 4 5 
    // 4 5 6 7 8     
    // 5 6 7 8 
    // 
    printf("----------------Printing Queue Starting from tail----------------\n");
    uint8_t* temp=Buff->tail;
    uint32_t i=0;
    for (i=0;i<Buff->count;i++)
    {
        printf("%d ",*temp);

        if(temp >= Buff->base + (Buff->size-1))
        {
            temp = Buff->base;
        }
        else
        {
            temp++;
        }
    }
    printf("\n");
}
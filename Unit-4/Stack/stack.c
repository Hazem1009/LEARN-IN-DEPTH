#include "stack.h"
Stack_Status Stack_init(Stack_t* Buffer,Stack_Data_Type* arr,uint32_t length)
{
    if(arr==NULL)
    {
        Buffer=NULL;
        Buffer->base=NULL;
        Buffer->head=NULL;
        Buffer->count=0;
        Buffer->length=0;
        return STACK_NULL;
    }
    Buffer->base=arr;
    Buffer->head=arr;
    Buffer->count=0;
    Buffer->length=length;
    return STACK_NO_ERROR;
}


Stack_Status Stack_Push(Stack_t* Buffer,uint8_t item)
{
    if(!Buffer || !Buffer->head || !Buffer->base)
    {
        return STACK_NULL;
    } 
    if(Stack_is_full(Buffer)==STACK_FULL)
    {
        return STACK_FULL;
    }
    *(Buffer->head)=item;
    Buffer->head++;
    Buffer->count++;
    return STACK_NO_ERROR;

}

Stack_Status Stack_Pop(Stack_t* Buffer,uint8_t* item)
{
    if(!Buffer || !Buffer->head || !Buffer->base)
    {
        return STACK_NULL;
    }  
    if(Buffer->count==0)
    {
        return STACK_EMPTY;
    }
    Buffer->head--;
    *item=*(Buffer->head);
    Buffer->count--;
    return STACK_NO_ERROR;
}



Stack_Status Stack_is_full(Stack_t* Buffer)
{
    if(!Buffer || !Buffer->head || !Buffer->base)
    {
        return STACK_NULL;
    }

    if(Buffer->length == Buffer->count)
    {
        return STACK_FULL;
    }

    return STACK_NOT_FULL;
}
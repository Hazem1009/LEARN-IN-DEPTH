/*Description: This header file contains the function prototypes of Queue.c file
* which implements the Queue data structure as circular buffer
* Created on: 24th July 2023
*Author: Hazem Hisham
*/

#ifndef QUEUE_H
#define QUEUE_H
#include <stdint.h>

typedef uint8_t Queue_Item;
typedef struct 
{
    uint32_t size;
    uint32_t count;
    Queue_Item *head;
    Queue_Item *tail;
    Queue_Item *base;
}Queue_t;

typedef enum
{
    QUEUE_NO_ERROR,
    QUEUE_FULL,
    QUEUE_NOT_FULL,
    QUEUE_EMPTY,
    QUEUE_NOT_EMPTY,
    QUEUE_NULL
}Queue_Status;


Queue_Status Queue_init(Queue_t* Buffer,Queue_Item* arr,uint32_t size);

Queue_Status Queue_enqueue(Queue_t* Buffer,Queue_Item item);

Queue_Status Queue_dequeue(Queue_t* Buffer,Queue_Item* item);

Queue_Status Queue_is_full(Queue_t* Buffer);

void Queue_Print(Queue_t*Buff);
#endif // QUEUE_H
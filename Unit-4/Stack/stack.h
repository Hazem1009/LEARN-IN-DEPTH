#include <stdint.h>
typedef  uint8_t Stack_Data_Type;
typedef struct 
{
    uint32_t length;
    uint32_t count;
    Stack_Data_Type* head;
    Stack_Data_Type* base;

}Stack_t;

typedef enum
{
    STACK_NO_ERROR,
    STACK_FULL,
    STACK_NOT_FULL,
    STACK_EMPTY,
    STACK_NOT_EMPTY,
    STACK_NULL
}Stack_Status;

Stack_Status Stack_init(Stack_t* Buffer,Stack_Data_Type* arr,uint32_t length);

Stack_Status Stack_Push(Stack_t* Buffer,uint8_t item);

Stack_Status Stack_Pop(Stack_t* Buffer,uint8_t* item);

Stack_Status Stack_is_full(Stack_t* Buffer);
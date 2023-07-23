#include <stdint.h>

void Reset_Handler();

extern void main();

/*STACK TOP = bss+1024(stack_TOP[256] as max is stack_Top[255])*/
static uint32_t stack_Top[256];

void Default_Handler()
{
	Reset_Handler();
}

void NMI_Handler() __attribute__ ((weak,alias("Default_Handler")));

void H_Fault_Handler() __attribute__ ((weak,alias("Default_Handler")));


/*VECTOR TABLE*/
void (*const g_Vector_table [] )() __attribute__((section(".vectors"))) =
{
	(void(*)())((uint32_t)stack_Top+sizeof(stack_Top)),
	Reset_Handler,
	NMI_Handler,
	H_Fault_Handler
};
/*END OF VECTOR TABLE*/


/*Linker Symbols to initialize .data and reserver .bss*/
extern uint32_t _E_TEXT;
extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_BSS;
extern uint32_t _E_BSS;

/*Reset Function*/

void Reset_Handler()
{
	//Copy Data from Flash to Ram in .data Section

	uint8_t* P_src = (uint8_t*)&_E_TEXT;
	uint8_t* P_dest = (uint8_t*)&_S_DATA;
	uint32_t data_size=(uint8_t*)&_E_DATA - (uint8_t*)&_S_DATA;

	for(uint32_t i= 0;i<data_size;i++)
	{
		*P_dest++=*P_src++;
	}

	//Initialize .bss segment with Zero initial value

	P_dest=(uint8_t*)&_S_BSS;
	data_size=(uint8_t*)&_E_BSS - (uint8_t*)&_S_BSS;
	for(uint32_t i= 0;i<data_size;i++)
	{
		*P_dest++=0;
	}	

	main();
}

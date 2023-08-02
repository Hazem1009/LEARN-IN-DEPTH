#include <stdint.h>
extern int main ();
#define STACK_TOP 	0x20001000
//extern uint32_t _stack_top ; 
extern uint32_t _E_TEXT;
extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_BSS;
extern uint32_t _E_BSS;

void reset_handler(void)
{
	/*Initialization of DATA segment*/
	uint32_t Data_size = (unsigned char*) &_E_DATA - (unsigned char*) &_S_DATA;
	unsigned char * p_src = (unsigned char*) & _E_TEXT;
	unsigned char * p_target = (unsigned char*) & _S_DATA;

	for(int i=0;i<Data_size;i++)
	{
		*p_target = *p_src;
		p_target++;
		p_src++;
	}

	/*Reservation of BSS Segment*/
	Data_size = (unsigned char*)&_E_BSS - (unsigned char*)&_S_BSS;
	p_target =  (unsigned char*) &_S_BSS;

	for(int i=0;i<Data_size;i++)
	{
		*p_target = 0;
		p_target++;
	}

	main();
}

void Default_handler(void)
{
	reset_handler();
}

void NMI_Handler (void) __attribute__((weak,alias ("Default_handler")));
void Hard_Fault_Handler (void) __attribute__((weak,alias ("Default_handler")));
void MM_Fault_Handler (void) __attribute__((weak,alias ("Default_handler")));
void Bus_Fault_Handler (void) __attribute__((weak,alias ("Default_handler")));
void Usage_Fault_Handler (void) __attribute__((weak,alias ("Default_handler")));


uint32_t vector_handler[] __attribute__((section(".vectors"))) = { 
	(uint32_t) STACK_TOP,
	(uint32_t)&reset_handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&Hard_Fault_Handler,
	(uint32_t)&MM_Fault_Handler,
	(uint32_t)&Bus_Fault_Handler,
	(uint32_t)&Usage_Fault_Handler
};
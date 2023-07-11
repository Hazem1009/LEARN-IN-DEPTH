#include "uart.h"

//Data register of UART0
#define UART0DR		*(volatile unsigned long*)(0x101F1000)

/*
*Description:Function used to send a string using UART
*/
void UART_SendString(unsigned char* str)
{	
	//loop until reaching a null character 
	while(*str!='\0')
	{

		UART0DR=(unsigned long) *str;
		str++;

	}
}

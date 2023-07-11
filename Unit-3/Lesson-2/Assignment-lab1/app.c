#include "uart.h"

unsigned char buffer[100]="learn-in-depth:<HAZEM HISHAM>";

const unsigned char buffer2[100]="learn-in-depth:<HAZEM HISHAM>";

void main(void)
{
	 UART_SendString(buffer);
}
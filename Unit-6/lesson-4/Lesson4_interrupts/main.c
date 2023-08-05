/*
 * main.c
 *
 *  Created on: Aug 5, 2023
 *      Author: Hazem
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define SET_BIT(REG,BIT) REG|=(1<<BIT)
#define RESET_BIT(REG,BIT) REG&=~(1<<BIT)
void EnableInterrupts()
{
	//Enable global interrupts.
	SREG|=(1<<7);
	//Configure External Interrupts Sense

	/*Configuration of Interrupt level Sensing*/
	//INT0 (ANY LOGICAL CHANGE) (0b01)
	SET_BIT(MCUCR,0);
	RESET_BIT(MCUCR,1);
	//INT1 (RISING EDGE)	(0b11)
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	//INT2 (FALLING EDGE) 	(write 0 to ISC2  in MCUCSR)
	RESET_BIT(MCUCSR,ISC2);

	/*Enable INT0 , INT1 ,INT2 in EXTI module*/
	GICR|=(1<<INT0)|(1<<INT1)|(1<<INT2);
}
ISR(INT0_vect)
{
	PORTD=0;
	PORTD|=(1<<5);
	_delay_ms(1000);

}
ISR(INT1_vect)
{
	PORTD=0;
	PORTD|=(1<<6);
	_delay_ms(1000);

}

ISR(INT2_vect)
{
	PORTD=0;
	SET_BIT(PORTD,PD7);
	_delay_ms(1000);
}

void main(void)
{
	PORTD=0x0000;
	EnableInterrupts();
	//PD2-PD3 as INPUT / PD5-PD6-PD7 as OUTPUT
	DDRD|=(1<<PD5)|(1<<PD6)|(1<<PD7);
	DDRD&=~(1<<PD2);
	DDRD&=~(1<<PD3);
	//PB2 as Input
	DDRB&=~(1<<PB2);
	while(1)
	{
		PORTD=0x0000;
	}
}

/*
 * CortexMX_OS_Porting.c
 *
 *  Created on: Sep 3, 2023
 *      Author: Hazem
 */
#include "CortexMX_OS_Porting.h"


//extern int g_test;


/*Function Description : Function Used By RTOS Schedular when User Calls OS_HWINIT API
 * INPUT:NONE
 * OUTPUT:PORTING_ERROR_t (E_OK /E_NOT_OK)
 * */
PORTING_ERROR_t HW_init(void)
{
	PORTING_ERROR_t error=E_OK;

	/*USER IS NOT ALLOWED TO SELECT FREQUENCY FOR THIS VERSION*/
	/* Assuming F_CPU is Default 8 MHZ
	 *         1 Tick -> 0.125 us
	 *         x Tick -> 1ms
	 *         x=8000 SYSTICK IS RELOADED WITH VALUE 8000 for 1ms Ticker
	 * */
	// StartOSTicker();


	/*Set PENDSV priority to be less than SVC and Systick As We don't want it to interrupt Systick as
	 * it would make PENDSV Context Switching pointless in this case as we are saving Systick Stack
	 *not the task
	 * */
	__NVIC_SetPriority(PendSV_IRQn,15);

	return error;
}


void SVC_Handler(void)
{

}

void SysTick_Handler(void)
{

}

//void PendSV_Handler(void)
//{
//	g_test++;
//
//}

void Trigger_PendSV(void)
{
	/* SCB->ICSR
	 * [28] PENDSVSET RW PendSV set-pending bit.
	Write:
	0 = no effect
	1 = changes PendSV exception state to pending.
	Read:
	0 = PendSV exception is not pending
	1 = PendSV exception is pending.
	Writing 1 to this bit is the only way to set the PendSV exception state to pending.
	[27] PENDSVCLR WO PendSV clear-pending bit.
	Write:
	0 = no effect
	1 = removes the pending state from the PendSV exception.*/
	SCB->ICSR|=(1<<28);
}

/*Function Description : Function Used By RTOS Schedular when User Calls StartOS API
 * INPUT:NONE
 * OUTPUT:PORTING_ERROR_t (E_OK /E_NOT_OK)
 * */
PORTING_ERROR_t StartOSTicker()
{
	PORTING_ERROR_t error=E_OK;

	/* Assuming F_CPU is Default 8 MHZ
	 *         1 Tick -> 0.125 us
	 *         x Tick -> 1ms
	 *         x=8000 SYSTICK IS RELOADED WITH VALUE 8000 for 1ms Ticker
	 * */
	SysTick_Config(8000);

	return error;

}

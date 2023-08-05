/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "Platform_Types.h"

#define RCC_BASE 				0x40021000
#define GPIO_PORTA				0x40010800


#define RCC_APB2ENR 		*(volatile uint32*)(0x40021018)
#define RCC_CFGR			*(volatile uint32*)(RCC_BASE+0x04)
#define RCC_CR				*(volatile uint32*)(RCC_BASE+0x00)
#define GPIO_PORTA_CRH		*(volatile uint32*)(0x40010804)
#define GPIO_PORTA_ODR		*(volatile uint32*)(0x4001080C)

#define IAOPEN 	(1<<2);
#define PIN13	(1UL<<13);



void clock_init()
{
	// APB1 Bus frequency 16MHZ
	//  APB2 Bus frequency 8MHZ
	//  AHB frequency 32 MHZ
	//  SysClk 32 MHZ 
	//  Use only internal HSI_RC
	// 	configure PLL multiplier

	/*Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	Set and cleared by software to control the division factor of the APB high-speed clock
	(PCLK2).
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16*/
	RCC_CFGR|=(0b101<<11); // 32MHZ/4 = 8MHZ for ABP2

	/*Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	Set and cleared by software to control the division factor of the APB low-speed clock
	(PCLK1).
	Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16*/
	RCC_CFGR|=(0b100<<8);	// 32MHZ/2 = 16MHZ for ABP1

	
	// 	Bits 1:0 SW: System clock switch
	// Set and cleared by software to select SYSCLK source.
	// Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of
	// failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security
	// System is enabled).
	// 00: HSI selected as system clock
	// 01: HSE selected as system clock
	// 10: PLL selected as system clock
	// 11: not allowed
	RCC_CFGR |= (0b10<<0); // PLL SELECTED AS SYSTEM CLOCK

	/*
	Bits 21:18 PLLMUL: PLL multiplication factor
	These bits are written by software to define the PLL multiplication factor. These bits can be
	written only when PLL is disabled.
	Caution: The PLL output frequency must not exceed 72 MHz.
	0000: PLL input clock x 2
	0001: PLL input clock x 3
	0010: PLL input clock x 4
	*/
	RCC_CFGR|=(0b0010<<18); // INPUT CLOCK (8MHZ) * 4 =32 MHZ FOR SySCLCK

	// 	Bit 24 PLLON: PLL enable
	// Set and cleared by software to enable PLL.
	// Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
	// PLL clock is used as system clock or is selected to become the system clock.
	// 0: PLL OFF
	// 1: PLL ON
	RCC_CR|=(1<<24); // PLL ENABLE 




}

int main(void)
{
	clock_init();
	RCC_APB2ENR|=IAOPEN;
	GPIO_PORTA_CRH&=0xFF0FFFFF;

	GPIO_PORTA_CRH|=0x00200000;
	/* Loop forever */
	while(1)
	{
		GPIO_PORTA_ODR|=(1<<13); //toggle
		int i=15;
		i++;
		for(i=0;i<700;i++)
		{

		}
		GPIO_PORTA_ODR&=~(1<<13);
		for(i=0;i<700;i++)
		{

		}


	}
}
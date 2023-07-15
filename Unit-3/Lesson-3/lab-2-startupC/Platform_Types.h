/*
 * Platform_Types.h
 *
 *  Created on: Jul 8, 2023
 *      Author: Hazem
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#ifndef _Bool
#define _Bool unsigned char
#endif
/*------------------ENUMERATIONS------------------*/
typedef enum{
	CPU_TYPE_8,
	CPU_TYPE_16,
	CPU_TYPE_32,
	CPU_TYPE_64
}CpuType;

typedef enum{
	MSB_FIRST,
	LSB_FIRST
}Bit_Order;



typedef enum{
	HIGH_BYTE_FIRST,
	LOW_BYTE_FIRST
}Byte_Order;
/*------------------END OF ENUMERATIONS------------------*/

#define false	0
#define true	1

#ifndef TRUE
#define TRUE true
#endif
#ifndef FALSE
#define FALSE false
#endif

/*Configurable per Architecture*/
#define CPU_TYPE	CPU_TYPE_32
#define BIT_ORDER	LSB_FIRST
#define BYTE_ORDER	LOW_BYTE_FIRST

/*Type Definitions*/
typedef _Bool 	boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef	unsigned long long uint64;

typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef	signed long long sint64;

typedef float float32;
typedef double float64;

typedef void* VoidPtr;
typedef const void* ConstVoidPtr;

#endif /* PLATFORM_TYPES_H_ */

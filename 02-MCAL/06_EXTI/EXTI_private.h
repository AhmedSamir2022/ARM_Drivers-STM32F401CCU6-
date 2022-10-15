/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 8/9/2022           */

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;

}EXTI_MemoryMap;

#define EXTI               ((volatile EXTI_MemoryMap*)0x40013C00)

#endif

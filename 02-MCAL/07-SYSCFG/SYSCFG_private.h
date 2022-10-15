/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 8/9/2022           */

#ifndef SYSCFG_PRIVATE_H
#define SYSCFG_PRIVATE_H

typedef struct
{
	volatile u32 MEMRMP;
	volatile u32 PMC;
	volatile u32 EXTICR[4];
	volatile u32 CMPCR;

}SYSCFG_MemoryMap;

#define SYSCFG              ((volatile SYSCFG_MemoryMap*)0x40013800)

#endif

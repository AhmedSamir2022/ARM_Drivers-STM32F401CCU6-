/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 28/8/2022           */

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_BASE_ADDRESS               (u32)0xE000E100

typedef struct
{
	volatile u32 ISER[8];		// Interrupt set-enable register
	volatile u32 Reserved1[24];
	volatile u32 ICER[8];		// Interrupt clear-enable register
	volatile u32 Reserved2[24];
	volatile u32 ISPR[8];		// Interrupt set-pending register
	volatile u32 Reserved3[24];
	volatile u32 ICPR[8];		// Interrupt clear-pending register
	volatile u32 Reserved4[24];
	volatile u32 IABR[8];		// Interrupt active bit register
	volatile u32 Reserved5[56];
	volatile u8	 IPR[240];		// Interrupt priority register
	volatile u32 Reserved6[400];
	volatile u32 STIR;			// Software trigger interrupt register
}NVIC_MemoryMap;

#define NVIC        ((volatile NVIC_MemoryMap*)NVIC_BASE_ADDRESS)

#define MNVIC_GROUP_4_SUB_0            0x05FA0300
#define MNVIC_GROUP_3_SUB_1            0x05FA0400
#define MNVIC_GROUP_2_SUB_2            0x05FA0500
#define MNVIC_GROUP_1_SUB_3            0x05FA0600
#define MNVIC_GROUP_0_SUB_4            0x05FA0700

#endif

/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 21/8/2022           */

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/* GPIOs Address Bus */
#define GPIOA_ADDRESS_BASE                    (u32)0x40020000
#define GPIOB_ADDRESS_BASE                    (u32)0x40020400
#define GPIOC_ADDRESS_BASE                    (u32)0x40020800

typedef struct
{
	u32	MODER;		// GPIO Mode Register
	u32 OTYPER;		// GPIO Output Type Register
	u32 OSPEEDR;	// GPIO Output Speed Register
	u32 PUPDR;		// GPIO Pull up\down Register
	u32 IDR;		// GPIO Input Data Register
	u32 ODR;		// GPIO Output Data Register
	u16 BSR;		// GPIO Bit Set Register
	u16 BRR;		// GPIO Bit Reset Register
	u32 LCKR;		// GPIO Configuration Lock Register
	u32 AFRL;		// GPIO Alternate Function Low Register
	u32 AFRH;		// GPIO Alternate Function High Register
}GPIO_MemoryMap;

#define	GPIOA			( (volatile GPIO_MemoryMap *)(GPIOA_ADDRESS_BASE) )
#define	GPIOB			( (volatile GPIO_MemoryMap *)(GPIOB_ADDRESS_BASE) )
#define	GPIOC			( (volatile GPIO_MemoryMap *)(GPIOC_ADDRESS_BASE) )

#endif

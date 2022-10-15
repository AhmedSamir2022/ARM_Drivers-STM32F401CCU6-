/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 12/8/2022           */

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* Base Address of RCC */
#define RCC_BASE_ADDRESS             (u32)0x40023800

/* Registers Definitions */

typedef struct
{
	u32 RCC_CR;
	u32 RCC_PLLCFGR;
	u32 RCC_CFGR;
	u32 RCC_CIR;
	u32 RCC_AHB1RSTR;
	u32 RCC_AHB2RSTR;
	u32 Reserved1;
	u32 Reserved2;
	u32 RCC_APB1RSTR;
	u32 RCC_APB2RSTR;
	u32 Reserved3;
	u32 Reserved4;
    u32 RCC_AHB1ENR;
    u32 RCC_AHB2ENR;
	u32 Reserved5;
	u32 Reserved6;
	u32 RCC_APB1ENR;
	u32 RCC_APB2ENR;
	u32 Reserved7;
	u32 Reserved8;
    u32 RCC_AHB1LPELR;
    u32 RCC_AHB2LPELR;
	u32 Reserved9;
	u32 Reserved10;
    u32 RCC_APB1LPELR;
    u32 RCC_APB2LPELR;
	u32 Reserved11;
	u32 Reserved12;
	u32	RCC_BDCR;
	u32	RCC_CSR;
	u32 Reserved13;
	u32 Reserved14;
	u32	RCC_SSCGR;
	u32	RCC_PLLI2SCFGR;

}RCC_t;

#define RCC         ((volatile RCC_t*)RCC_BASE_ADDRESS)



#endif

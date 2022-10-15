/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 28/8/2022           */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

/* this function is shit */
void MNVIC_voidInit(void)
{
    #define SCB_AAIRCR      *((u32*)(0xE000ED00 + 0x0C))
	SCB_AAIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}

void MNVIC_EnableInterrupt (u8 Copy_u8InterruptID)
{
	NVIC->ISER[Copy_u8InterruptID/32] = 1 << Copy_u8InterruptID%32;
}
void MNVIC_DisableInterrupt (u8 Copy_u8InterruptID)
{
	NVIC->ICER[Copy_u8InterruptID/32] = 1 << Copy_u8InterruptID%32;
}

void MNVIC_SetPendingFlag (u8 Copy_u8InterruptID)
{
	NVIC->ISPR[Copy_u8InterruptID/32] = 1 << Copy_u8InterruptID%32;
}

void MNVIC_ClearPendingFlag (u8 Copy_u8InterruptID)
{
	NVIC->ICPR[Copy_u8InterruptID/32] = 1 << Copy_u8InterruptID%32;
}

u8 MNVIC_GetActiveFlag (u8 Copy_u8InterruptID)
{
	u8 Result = 0;
	Result = GET_BIT( NVIC->IABR[Copy_u8InterruptID/32], Copy_u8InterruptID%32 );
	return Result;
}

void MNVIC_voidSetPriority(u8 Copy_u8InterruptIdx,u8 Copy_u8Priority)
{
	if(Copy_u8InterruptIdx < 60)
	{
		NVIC->IPR[Copy_u8InterruptIdx] = Copy_u8Priority;
	}
	else
	{
		//report error
	}
}

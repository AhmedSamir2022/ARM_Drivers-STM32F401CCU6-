/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 2/9/2022            */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

u8 flag = 0;
/* Global Pointer to function */
void (*CallBack)(void);

void MSTK_voidInit(void)
{
	/* Disable Systick */
	STK->CTRL &= ~ (1 << 0);
	/* Disable Systick Interrupt */
	STK->CTRL &= ~ (1 << 1);
	/* Select STK clock from configuration file */
	STK->CTRL &= ~ (1 << 2);
	STK->CTRL |= ((STK_CLOCK) << 2);
}

void MSTK_voidSetBusyWait(u32 Copy_u8Ticks)
{
	/* load ticks to load register */
	STK->LOAD = Copy_u8Ticks;
	/* Enable STK_COUNTER */
	STK->CTRL |= (1 << 0);
	/* processor wait to flag be 1 */
	while(!(((STK->CTRL) >> 16) & 1));
}

void MSTK_voidSetIntervalSingle(u32 Copy_u8Ticks , void (*Copy_ptr)(void) )
{
	/* Disable Timer */
	STK->CTRL &= ~ (1 << 0);
	STK->VAL = 0;
	/* load ticks to load register */
	STK->LOAD = Copy_u8Ticks;
	/* Enable STK_COUNTER */
	STK->CTRL |= (1 << 0);
	/* Enable STK interrupt */
	STK->CTRL |= (1 << 1);

	flag = 1;
	CallBack = Copy_ptr;

}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u8Ticks , void (*Copy_ptr)(void) )
{
	/* load ticks to load register */
	STK->LOAD = Copy_u8Ticks;
	/* Enable STK_COUNTER */
	STK->CTRL |= (1 << 0);
	/* Enable STK interrupt */
	STK->CTRL |= (1 << 1);

	flag = 2;
	CallBack = Copy_ptr;

}

/* ISR */
void SysTick_Handler(void)
{
	if(flag == 1)
	{
		STK->LOAD = 0;
		STK->VAL = 0;
	}

	CallBack();
}

void MSTK_voidStopTimer(void)
{
	/* Disable Systick */
	STK->CTRL &= ~ (1 << 0);
	/* Disable Systick Interrupt */
	STK->CTRL &= ~ (1 << 1);

	STK->LOAD = 0;
	STK->VAL = 0;
}

u32 MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32Return = 0;

	Local_u32Return = (STK->LOAD - STK->VAL);

	return Local_u32Return;
}

u32 MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32Return = 0;
	/* Read the value in Value_register */
	Local_u32Return = STK->VAL;

	return Local_u32Return;
}

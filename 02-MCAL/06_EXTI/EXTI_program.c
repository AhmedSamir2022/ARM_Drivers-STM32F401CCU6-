/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 8/9/2022           */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

// Global Pointer to Function to Hold EXTI ISR Address
void (*EXTI_EXTI0Function)(void) = NULL;
void (*EXTI_EXTI1Function)(void) = NULL;
void (*EXTI_EXTI2Function)(void) = NULL;
void (*EXTI_EXTI3Function)(void) = NULL;
void (*EXTI_EXTI4Function)(void) = NULL;
void (*EXTI_EXTI9_5Function)(void) = NULL;
void (*EXTI_EXTI15_10Function)(void) = NULL;


void EXTI_voidEnableTriggerLine (u8 Copy_u8LineID, u8 Copy_u8Trigger)
{
	/* EnableInterrupt */
	EXTI->IMR |= (1 << Copy_u8LineID);
	/* Set Trigger */
	switch(Copy_u8Trigger)
	{
	case EXTI_FALLING_EDGE:
		EXTI->FTSR |= (1 << Copy_u8LineID);
		break;
	case EXTI_RISING_EDGE:
		EXTI->RTSR |= (1 << Copy_u8LineID);
		break;
	case EXTI_ON_CHANGE:
		EXTI->FTSR |= (1 << Copy_u8LineID);
		EXTI->RTSR |= (1 << Copy_u8LineID);
		break;
	default : //error
		break;
	}
}

void EXTI_voidDisableLine (u8 Copy_u8LineID)
{
	EXTI->IMR &= ~(1 << Copy_u8LineID);
	EXTI->IMR |= (0 << Copy_u8LineID);
}

void EXTI_voidSoftWareTrigger (u8 Copy_u8LineID)
{
	EXTI->SWIER |= (1 << Copy_u8LineID);
}

void EXTI_voidCallBack (u8 Copy_u8LineID, void (*EXTIFunction)(void))
{
	if(Copy_u8LineID == EXTI_LINE0)
		EXTI_EXTI0Function = EXTIFunction;
	else if(Copy_u8LineID == EXTI_LINE1)
		EXTI_EXTI1Function = EXTIFunction;
	else if(Copy_u8LineID == EXTI_LINE2)
		EXTI_EXTI2Function = EXTIFunction;
	else if(Copy_u8LineID == EXTI_LINE3)
		EXTI_EXTI3Function = EXTIFunction;
	else if(Copy_u8LineID == EXTI_LINE4)
		EXTI_EXTI4Function = EXTIFunction;
	else if(Copy_u8LineID <= EXTI_LINE9)
		EXTI_EXTI9_5Function = EXTIFunction;
	else if(Copy_u8LineID <= EXTI_LINE15)
		EXTI_EXTI15_10Function = EXTIFunction;
}

/* ISR of EXTI0 */
void EXTI0_IRQHandler(void)
{
	if (EXTI_EXTI0Function != NULL)
		EXTI_EXTI0Function();

	else
	{
		/* Do Nothing */
	}
	SET_BIT(EXTI->PR , EXTI_LINE0); // Clear Flag
}
/* ISR of EXTI1 */
void EXTI1_IRQHandler(void)
{
	if (EXTI_EXTI1Function != NULL)
		EXTI_EXTI1Function();

	else
	{
		/* Do Nothing */
	}
	SET_BIT(EXTI->PR, EXTI_LINE1); // Clear Flag
}

/* ISR of EXTI2 */
void EXTI2_IRQHandler(void)
{
	if (EXTI_EXTI2Function != NULL)
		EXTI_EXTI2Function();

	else
	{
		/* Do Nothing */
	}
	SET_BIT(EXTI->PR, EXTI_LINE2); // Clear Flag
}

/* ISR of EXTI3 */
void EXTI3_IRQHandler(void)
{
	if (EXTI_EXTI3Function != NULL)
		EXTI_EXTI3Function();

	else
	{
		/* Do Nothing */
	}
	SET_BIT(EXTI->PR, EXTI_LINE3); // Clear Flag
}

/* ISR of EXTI4 */
void EXTI4_IRQHandler(void)
{
	if (EXTI_EXTI4Function != NULL)
		EXTI_EXTI4Function();

	else
	{
		/* Do Nothing */
	}
	SET_BIT(EXTI->PR, EXTI_LINE5); // Clear Flag
}

/* ISR of EXTI5:9 */
void EXTI9_5_IRQHandler(void)
{
	if (EXTI_EXTI9_5Function != NULL)
	EXTI_EXTI9_5Function();

	else
	{
		/* Do Nothing */
	}
	SET_BIT(EXTI->PR , EXTI_LINE5); // Clear Flag
	SET_BIT(EXTI->PR , EXTI_LINE6);
	SET_BIT(EXTI->PR , EXTI_LINE7);
	SET_BIT(EXTI->PR , EXTI_LINE8);
	SET_BIT(EXTI->PR , EXTI_LINE9);
}

/* ISR of EXTI10:15 */
void EXTI15_10_IRQHandler(void)
{
	if (EXTI_EXTI15_10Function != NULL)
	EXTI_EXTI15_10Function();

	else
	{
		/* Do Nothing */
	}
	SET_BIT(EXTI->PR , EXTI_LINE10); // Clear Flag
	SET_BIT(EXTI->PR , EXTI_LINE11);
	SET_BIT(EXTI->PR , EXTI_LINE12);
	SET_BIT(EXTI->PR , EXTI_LINE13);
	SET_BIT(EXTI->PR , EXTI_LINE14);
	SET_BIT(EXTI->PR , EXTI_LINE15);
}

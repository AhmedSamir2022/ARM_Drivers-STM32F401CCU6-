/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 10/9/2022           */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "PORT_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "SYSCFG_interface.h"
#include "STK_interface.h"

#include "IR_interface.h"
#include "IR_config.h"
#include "IR_private.h"


void IR_voidInit(void)
{
	/* SYSCFG Initialization */
	SYSCFG_voidSetEXTIPort(IR_EXTIID,IR_EXTIPORT);
	/* EXTI Initialization */
	EXTI_voidCallBack(IR_EXTIID,GetIRFrame);
	EXTI_voidEnableTriggerLine(IR_EXTIID,EXTI_FALLING_EDGE);
}

void IR_voidConfigCharacter(u8 Copy_u8RemoteCharacter,void (*Copyptr)(void))
{
	switch(Copy_u8RemoteCharacter)
	{
	case REMOTE_POWER   : REMOTE_POWERFunction = Copyptr;    break;
	case REMOTE_MODE    : REMOTE_MODEFunction = Copyptr;     break;
	case REMOTE_SILENT  : REMOTE_SILENTFunction = Copyptr;   break;
	case REMOTE_PAUSE   : REMOTE_PAUSEFunction = Copyptr;    break;
	case REMOTE_LEFT    : REMOTE_LEFTFunction = Copyptr;     break;
	case REMOTE_EQ      : REMOTE_EQFunction = Copyptr;       break;
	case REMOTE_VOL_LOW : REMOTE_VOL_LOWFunction = Copyptr;  break;
	case REMOTE_VOL_HIGH: REMOTE_VOL_HIGHFunction = Copyptr; break;
	case REMOTE_RPT     : REMOTE_RPTFunction = Copyptr;      break;
	case REMOTE_U_SD    : REMOTE_U_SDFunction = Copyptr;     break;
	case REMOTE_ZERO    : REMOTE_ZEROFunction = Copyptr;     break;
	case REMOTE_ONE     : REMOTE_ONEFunction = Copyptr;      break;
	case REMOTE_TWO     : REMOTE_TWOFunction = Copyptr;      break;
	case REMOTE_THREE   : REMOTE_THREEFunction = Copyptr;    break;
	case REMOTE_FOUR    : REMOTE_FOURFunction = Copyptr;     break;
	case REMOTE_FIVE    : REMOTE_FIVEFunction = Copyptr;     break;
	case REMOTE_SIX     : REMOTE_SIXFunction = Copyptr;      break;
	case REMOTE_SEVEN   : REMOTE_SEVENFunction = Copyptr;    break;
	case REMOTE_EIGHT   : REMOTE_EIGHTFunction = Copyptr;    break;
	case REMOTE_NINE    : REMOTE_NINEFunction = Copyptr;     break;
	default             : /*error*/                  break;
	}

}


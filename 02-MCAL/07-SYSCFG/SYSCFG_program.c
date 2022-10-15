/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 8/9/2022           */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSCFG_interface.h"
#include "SYSCFG_config.h"
#include "SYSCFG_private.h"

void SYSCFG_voidSetEXTIPort(u8 Copy_u8EXTILine , u8 Copy_u8Port)
{
	SYSCFG->EXTICR[Copy_u8EXTILine / 4] &= ~ ((Copy_u8Port) << (Copy_u8EXTILine % 4)*4);
	SYSCFG->EXTICR[Copy_u8EXTILine / 4] |= ((Copy_u8Port) << (Copy_u8EXTILine % 4)*4);
}

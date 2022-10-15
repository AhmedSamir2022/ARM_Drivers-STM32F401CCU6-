/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 12/8/2022           */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInit(void)
{
	RCC->RCC_PLLCFGR = 0x00;

	RCC->RCC_PLLCFGR |= ((RCC_PLLM) << 0);
	RCC->RCC_PLLCFGR |= ((RCC_PLLN) << 6);
	RCC->RCC_PLLCFGR |= ((RCC_PLLP) << 16);
	RCC->RCC_PLLCFGR |= ((RCC_PLLSRC) << 22);
	RCC->RCC_PLLCFGR |= ((RCC_PLLQ) << 24);

	RCC->RCC_CFGR = 0x00;

	RCC->RCC_CFGR |= (RCC_SYSTEM_CLOCK << 0);
	RCC->RCC_CFGR |= (RCC_AHB_PRE_VALUE << 4);
	RCC->RCC_CFGR |= (RCC_APB1_PRE_VALUE << 10);
	RCC->RCC_CFGR |= (RCC_APB2_PRE_VALUE << 13);
	RCC->RCC_CFGR |= (RCC_RTC_PRE_VALUE << 16);
	RCC->RCC_CFGR |= (RCC_RCC_MCO1_SRC << 21);
	RCC->RCC_CFGR |= (RCC_RCC_I2S_SRC << 23);
	RCC->RCC_CFGR |= (RCC_RCC_MCO1PRE << 24);
	RCC->RCC_CFGR |= (RCC_RCC_MCO2PRE << 27);
	RCC->RCC_CFGR |= (RCC_RCC_MCO2_SRC << 30);

	RCC->RCC_CR = 0x00;

	RCC->RCC_CR |= ((RCC_HSI_ON) << 0);
	if(RCC_TRIMMING_VAL<32)
		RCC->RCC_CR |= (RCC_TRIMMING_VAL << 3);
	RCC->RCC_CR |= (RCC_HSE_ON << 16);
	RCC->RCC_CR |= (RCC_HSE_BYPASS << 18);
	RCC->RCC_CR |= (RCC_CSS_ON << 19);
	RCC->RCC_CR |= (RCC_PLL_ON << 24);
	RCC->RCC_CR |= (RCC_PLLI2S_ON << 26);

}

void RCC_voidPeripheralClockEnable(u8 Copy_u8BusName, Peripherals_t Copy_u8PerphiralName)
{
	switch(Copy_u8BusName)
	{
	case RCC_AHB1: SET_BIT(RCC->RCC_AHB1ENR,Copy_u8PerphiralName); break;
	case RCC_AHB2: SET_BIT(RCC->RCC_AHB2ENR,Copy_u8PerphiralName); break;
	case RCC_APB1: SET_BIT(RCC->RCC_APB1ENR,Copy_u8PerphiralName); break;
	case RCC_APB2: SET_BIT(RCC->RCC_APB2ENR,Copy_u8PerphiralName); break;
	}
}
void RCC_voidPeripheralClockDisable(u8 Copy_u8BusName, Peripherals_t Copy_u8PerphiralName)
{
	switch(Copy_u8BusName)
	{
	case RCC_AHB1: CLR_BIT(RCC->RCC_AHB1ENR,Copy_u8PerphiralName); break;
	case RCC_AHB2: CLR_BIT(RCC->RCC_AHB2ENR,Copy_u8PerphiralName); break;
	case RCC_APB1: CLR_BIT(RCC->RCC_APB1ENR,Copy_u8PerphiralName); break;
	case RCC_APB2: CLR_BIT(RCC->RCC_APB2ENR,Copy_u8PerphiralName); break;
	}
}

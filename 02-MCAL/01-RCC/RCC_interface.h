/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 12/8/2022           */

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/* Buses Names */
#define RCC_AHB1			0
#define RCC_AHB2			1
#define RCC_APB1		    2
#define RCC_APB2	      	3

/* System Clock Options */
#define RCC_HSI                         0
#define RCC_HSE                         1
#define RCC_PLL                         2

/* MCO1 Source Options */
#define RCC_MCO1_HSI                    0
#define RCC_MCO1_LSE                    1
#define RCC_MCO1_HSE                    2
#define RCC_MCO1_PLL                    3

/* MCO1 Prescaler Options */
#define RCC_MCO1PRE_NO                  0
#define RCC_MCO1PRE_2                   4
#define RCC_MCO1PRE_3                   5
#define RCC_MCO1PRE_4                   6
#define RCC_MCO1PRE_5                   7

/* MCO2 Source Options */
#define RCC_MCO2_SYSCLK                 0
#define RCC_MCO2_PLLI2S                 1
#define RCC_MCO2_HSE                    2
#define RCC_MCO2_PLL                    3

/* MCO2 Prescaler Options */
#define RCC_MCO2PRE_NO                  0
#define RCC_MCO2PRE_2                   4
#define RCC_MCO2PRE_3                   5
#define RCC_MCO2PRE_4                   6
#define RCC_MCO2PRE_5                   7

/* I2S Source Options */
#define RCC_I2S_PLLI2S                  0
#define RCC_I2S_HSE                     1

/* AHB Prescaler Options */
#define RCC_AHB_PRE_NO	                0
#define RCC_AHB_PRE_2	                8
#define RCC_AHB_PRE_4	                9
#define RCC_AHB_PRE_8	                10
#define RCC_AHB_PRE_16	                11
#define RCC_AHB_PRE_64	                12
#define RCC_AHB_PRE_128	                13
#define RCC_AHB_PRE_256	                14
#define RCC_AHB_PRE_512	                15
/* APB1 Prescaler Options */
#define RCC_APB1_PRE_NO	                0
#define RCC_APB1_PRE_2	                4
#define RCC_APB1_PRE_4	                5
#define RCC_APB1_PRE_8	                6
#define RCC_APB1_PRE_16	                7
/* APB2 Prescaler Options */
#define RCC_APB2_PRE_NO	                0
#define RCC_APB2_PRE_2	                4
#define RCC_APB2_PRE_4	                5
#define RCC_APB2_PRE_8	                6
#define RCC_APB2_PRE_16	                7

typedef enum
{
	GPIO_A,
	GPIO_B,
	GPIO_C,
	GPIO_D,
	GPIO_E,
	GPIO_H=7,
	CRC=12,
	DMA1=21,
	DMA2,
	OTGFS=7,
	TIM2=0,
	TIM3,
	TIM4,
	TIM5,
	WWDG=11,
	SPI2=14,
	SPI3,
	USART2=17,
	I2C1=21,
	I2C2,
	I2C3,
	PWR=28,
	TIM1=0,
	USART1=4,
	USART6,
	ADC1=8,
	SDIO=11,
	SPI1,
	SPI4,
	SYSCFG,
	TIM9=16,
	TIM10,
	TIM11

}Peripherals_t;


/* funcyions prototypes */
void RCC_voidInit(void);
void RCC_voidPeripheralClockEnable(u8 Copy_u8BusName, Peripherals_t Copy_u8PerphiralName);
void RCC_voidPeripheralClockDisable(u8 Copy_u8BusName, Peripherals_t Copy_u8PerphiralName);



#endif

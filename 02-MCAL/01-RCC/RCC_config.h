/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 12/8/2022           */

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/************************************************************************/
/* Select System Clock			 										*/
/*		 RCC_HSI_ON 														*/
/* 			--> HSI ON		1											*/
/* 			--> HSI OFF		0											*/
/*		 RCC_HSE_ON	 													*/
/* 			--> HSE ON		1											*/
/* 			--> HSE OFF		0											*/
/*		 RCC_PLL_ON														*/
/*			--> PLL ON		1											*/
/*			--> PLL OFF		0											*/
/*		 RCC_PLLI2S_ON													*/
/*			--> PLLI2S ON		1										*/
/*			--> PLLI2S OFF		0										*/
/************************************************************************/
#define RCC_HSE_ON                  1  // enable state of HSE 1: on , 0: off
#define RCC_HSI_ON                  1
#define RCC_PLL_ON                  0
#define RCC_PLLI2S_ON               0

#define RCC_TRIMMING_VAL            16
/************************************************************************/
/* Initialize HSE Clock Bypass											*/
/*		 RCC_HSE_BYPASS													*/
/*			--> Bypass	 		1	 									*/
/*			--> NotBybass		0										*/
/************************************************************************/
#define RCC_HSE_BYPASS              0
/************************************************************************/
/* Initialize Clock Security System										*/
/*		 CSSBit														*/
/*			--> CSS ON		1											*/
/*			--> CSS OFF		0											*/
/************************************************************************/
#define RCC_CSS_ON                  0

/*
Optoins:
-RCC_HSI
-RCC_HSE
-RCC_PLL
*/
#define RCC_SYSTEM_CLOCK           RCC_HSI

#define RCC_AHB_PRE_VALUE          RCC_AHB_PRE_2
#define RCC_APB1_PRE_VALUE         RCC_APB1_PRE_NO
#define RCC_APB2_PRE_VALUE         RCC_APB2_PRE_NO
/*
 no clock >> 0 or 1
 /2 >>2
 /3 >>3
 .
 .
 /31 >>31
 */
#define RCC_RTC_PRE_VALUE          0

/********************************************************************************************/
/* Define PLLM: Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock	*/
/*     These bits can be written only when the PLL and PLLI2S are disabled					*/
/* set these bits to ensure that the VCO input frequency ranges from 1 to 2 MHz				*/
/*		000000: PLLM = 0, wrong configuration											   	*/
/*		000001: PLLM = 1, wrong configuration												*/
/*		000010: PLLM = 2 																	*/
/*		000011: PLLM = 3 																	*/
/*		000100: PLLM = 4 																	*/
/*		...              																	*/
/*		111110: PLLM = 62																	*/
/*		111111: PLLM = 63																	*/
/********************************************************************************************/
#define RCC_PLLM                   2

/************************************************************************************************/
/* Define PLLN: Multiplication factor for the main PLL (PLL)									*/
/*     These bits can be written only when the PLL is disabled									*/
/* set these bits to ensure that the VCO output frequency is between 192 and 432 MHz			*/
/*		000000: PLLM = 0, wrong configuration													*/
/*		000001: PLLM = 1, wrong configuration													*/
/*		...																						*/
/*		011000000: PLLN = 192																	*/
/*		...																						*/
/*		110110000: PLLN = 432																	*/
/*		110110001: PLLN = 433, wrong configuration												*/
/*		...																						*/
/*		111111111: PLLN = 511, wrong configuration												*/
/*		...																						*/
/************************************************************************************************/
#define RCC_PLLN                   2

/********************************************************************************/
/* Define PLLP: Main PLL (PLL) division factor for main system clock			*/
/*     These bits can be written only if PLL is disabled					    */
/*	set these bits to not exceed 84 MHz on this domain							*/
/*		0: PLLP = 2															*/
/*		1: PLLP = 4															*/
/*		2: PLLP = 6															*/
/*		3: PLLP = 8															*/
/********************************************************************************/
#define RCC_PLLP                   0

/************************************************************************************************************************/
/* Define  PLLSRC: Main PLL(PLL) and audio PLL (PLLI2S) entry clock source												*/
/*					0: HSI clock selected as PLL and PLLI2S clock entry													*/
/*					1: HSE oscillator clock selected as PLL and PLLI2S clock entry										*/
/*																														*/
/*			-	IF HSI oscillator clock selected:																		*/
/*					Define the input Clock -> 16000000																	*/
/*			-	IF HSE oscillator clock selected:																		*/
/*					Define the input Clock -> as your system clock														*/
/************************************************************************************************************************/
#define RCC_PLLSRC                 0
#define Finput	                   25000000

/* Options: 2 to15 */
#define RCC_PLLQ                   2

/************************************************************************************************/
/* Define MCO1: MicroController Generate clock output 1											*/
/* configure these bits only after reset before enabling the external oscillators and PLL		*/
/*				00: HSI clock selected						0									*/
/*				01: LSE oscillator selected					1									*/
/*				10: HSE oscillator clock selected			2									*/
/*				11: PLL clock selected						3									*/
/************************************************************************************************/
/* Options:-RCC_MCO1_HSI -RCC_MCO1_LSE -RCC_MCO1_HSE -RCC_MCO1_PLL */
#define RCC_RCC_MCO1_SRC           RCC_MCO1_HSI

/* Options: -RCC_I2S_HSE -RCC_I2S_PLLI2S */
#define RCC_RCC_I2S_SRC            RCC_I2S_HSE

/************************************************************************************************************************/
/* Define  MCO1PRE: MCO1 PreScaler																						*/
/*					0xx: no division 0																					*/
/*					100: division by 2																					*/
/*					101: division by 3																					*/
/*					110: division by 4																					*/
/*					111: division by 5																					*/
/************************************************************************************************************************/
/* Options:-RCC_MCO1PRE_NO -RCC_MCO1PRE_2 -RCC_MCO1PRE_3 -RCC_MCO1PRE_4 -RCC_MCO1PRE_5 */
#define RCC_RCC_MCO1PRE             RCC_MCO1PRE_NO

/************************************************************************************************************************/
/* Define  MCO2PRE: MCO2 PreScaler																						*/
/*					0xx: no division 0																					*/
/*					100: division by 2																					*/
/*					101: division by 3																					*/
/*					110: division by 4																					*/
/*					111: division by 5																					*/
/************************************************************************************************************************/
/* Options:-RCC_MCO2PRE_NO -RCC_MCO2PRE_2 -RCC_MCO2PRE_3 -RCC_MCO2PRE_4 -RCC_MCO2PRE_5 */
#define RCC_RCC_MCO2PRE             RCC_MCO2PRE_NO

/************************************************************************************************/
/* Define MCO2: MicroController Generate clock output 2											*/
/* configure these bits only after reset before enabling the external oscillators and PLL		*/
/*				00: System clock (SYSCLK) selected			0									*/
/*				01: PLLI2S clock selected					1									*/
/*				10: HSE oscillator clock selected			2									*/
/*				11: PLL clock selected						3									*/
/************************************************************************************************/
/* Options:-RCC_MCO2_SYSCLK -RCC_MCO2_PLLI2S -RCC_MCO2_HSE -RCC_MCO2_PLL */
#define RCC_RCC_MCO2_SRC           RCC_MCO2_SYSCLK

#endif

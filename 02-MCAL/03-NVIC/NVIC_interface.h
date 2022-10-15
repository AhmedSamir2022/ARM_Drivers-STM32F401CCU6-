/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 28/8/2022           */

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/****************************************************/
/* Define:	Interrupt Peripheral ID	from (0 to 239) */
/****************************************************/

void MNVIC_EnableInterrupt (u8 InterruptID);
void MNVIC_DisableInterrupt (u8 InterruptID);

void MNVIC_SetPendingFlag (u8 InterruptID);
void MNVIC_ClearPendingFlag (u8 InterruptID);

u8 MNVIC_GetActiveFlag (u8 InterruptID);

void MNVIC_voidSetPriority(u8 Copy_u8InterruptIdx,u8 Copy_u8Priority);
void MNVIC_voidInit(void);
#endif

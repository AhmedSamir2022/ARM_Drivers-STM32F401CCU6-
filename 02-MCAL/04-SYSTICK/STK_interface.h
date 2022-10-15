/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 2/9/2022            */

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

void MSTK_voidInit(void);

void MSTK_voidSetBusyWait(u32 Copy_u8Ticks);

void MSTK_voidSetIntervalSingle(u32 Copy_u8Ticks , void (*Copy_ptr)(void) );

void MSTK_voidSetIntervalPeriodic(u32 Copy_u8Ticks , void (*Copy_ptr)(void) );

void MSTK_voidStopTimer(void);

u32 MSTK_u32GetElapsedTime(void);

u32 MSTK_u32GetRemainingTime(void);


#endif

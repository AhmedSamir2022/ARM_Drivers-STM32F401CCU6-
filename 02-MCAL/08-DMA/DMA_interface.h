/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 23/9/2022           */

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H


void MDMA2_voidInit(void);
void MDMA2_voidStart(u32 *Copy_u32SourceAddress,u32 *Copy_u32DestAddress,u16 Copy_u16NumberOfDataItems);

#endif

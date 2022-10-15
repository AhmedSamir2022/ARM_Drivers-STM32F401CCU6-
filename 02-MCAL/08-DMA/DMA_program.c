/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 23/9/2022           */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_config.h"
#include "DMA_private.h"

void MDMA2_voidInit(void)
{
	if(DMA2->Streams[DMA_STREAM_NUMBER].SCR & 1)
	{
		CLR_BIT(DMA2->Streams[DMA_STREAM_NUMBER].SCR,0);
	}
	else
	{
		DMA2->Streams[DMA_STREAM_NUMBER].SCR = 0x00000000;
		/* Select the data direction */
		DMA2->Streams[DMA_STREAM_NUMBER].SCR &= ~(0b11 << 6);
		DMA2->Streams[DMA_STREAM_NUMBER].SCR |=  (DMA_TRANSFER_DIRECTION << 6);
		/* Set stream priority */
		DMA2->Streams[DMA_STREAM_NUMBER].SCR &= ~(0b11 << 16);
		DMA2->Streams[DMA_STREAM_NUMBER].SCR |=  (DMA_STREAM_PRIORITY << 16);
		/* set MSIZE & PSIZE */
		DMA2->Streams[DMA_STREAM_NUMBER].SCR &= ~(0b11 << 13);
		DMA2->Streams[DMA_STREAM_NUMBER].SCR |=  (DMA_MEMORY_SIZE << 13);
		DMA2->Streams[DMA_STREAM_NUMBER].SCR &= ~(0b11 << 11);
		DMA2->Streams[DMA_STREAM_NUMBER].SCR |=  (DMA_PERIPHERAL_SIZE << 11);
		/* Set Circular mode */
		DMA2->Streams[DMA_STREAM_NUMBER].SCR &= ~(0b1 << 8);
		DMA2->Streams[DMA_STREAM_NUMBER].SCR |=  (DMA_CIRCULAR_MODE << 8);
		/* Enable Interrupts */
		SET_BIT(DMA2->Streams[DMA_STREAM_NUMBER].SCR , 4);
		SET_BIT(DMA2->Streams[DMA_STREAM_NUMBER].SCR , 3);
		SET_BIT(DMA2->Streams[DMA_STREAM_NUMBER].SCR , 2);
		SET_BIT(DMA2->Streams[DMA_STREAM_NUMBER].SCR , 1);
		SET_BIT(DMA2->Streams[DMA_STREAM_NUMBER].SFCR , 7);
		/* Select Direct or FIFO Mode */
		DMA2->Streams[DMA_STREAM_NUMBER].SFCR &= ~(0b1 << 2);
		DMA2->Streams[DMA_STREAM_NUMBER].SFCR |=  (DMA_DIRECT_OR_FIFO_MODE << 2);
		/* Set FIFO Threshold */
		DMA2->Streams[DMA_STREAM_NUMBER].SFCR &= ~(0b11 << 1);
		DMA2->Streams[DMA_STREAM_NUMBER].SFCR |=  (DMA_FIFO_THRESHOLD << 1);

	}

}
void MDMA2_voidStart(u32 *Copy_u32SourceAddress,u32 *Copy_u32DestAddress,u16 Copy_u16NumberOfDataItems)
{
	/* Set the Source Address */
	DMA2->Streams[DMA_STREAM_NUMBER].SPAR = Copy_u32SourceAddress;
	/* Set the Destination Address */
	DMA2->Streams[DMA_STREAM_NUMBER].SMA0AR = Copy_u32DestAddress;
	/* Set number of data items */
	DMA2->Streams[DMA_STREAM_NUMBER].SNDTR = Copy_u16NumberOfDataItems;
	/* Enable Stream */
	SET_BIT(DMA2->Streams[DMA_STREAM_NUMBER].SCR , 0);

}

void DMA2_Stream0_IRQHandler(void)
{
	/* Clear Transfer complete flag */
	CLR_BIT(DMA2->LIFCR , 5);
}

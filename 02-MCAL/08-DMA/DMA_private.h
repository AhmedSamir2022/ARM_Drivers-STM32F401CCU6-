/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 23/9/2022           */

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

#define DMA1_BASEADDRESS      0x40026000
#define DMA2_BASEADDRESS      0x40026400

typedef struct
{
	u32 SCR;
	u32 SNDTR;
	u32 SPAR;
	u32 SMA0AR;
	u32 SMA1AR;
	u32 SFCR;

}stream_t;

typedef struct
{
	u32 LISR;
	u32 HISR;
	u32 LIFCR;
	u32 HIFCR;
	stream_t Streams[8];

}DMA_t;

#define DMA1        ((volatile DMA_t*)DMA1_BASEADDRESS)
#define DMA2        ((volatile DMA_t*)DMA2_BASEADDRESS)

#endif

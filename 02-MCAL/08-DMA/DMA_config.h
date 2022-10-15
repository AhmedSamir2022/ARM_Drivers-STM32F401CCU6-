/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 23/9/2022           */

#ifndef DMA_CONFIG_H
#define DMA_CONFIG_H

/* select stream number */
#define DMA_STREAM_NUMBER               0
/* options:
 -Peripheral-to-memory >> 0
 -Memory-to-peripheral >> 1
 -Memory-to-memory     >> 2
  */
#define DMA_TRANSFER_DIRECTION   2

/* select stream priority
 options:
 -Low       >> 0
 -Medium    >> 1
 -High      >> 2
 -veryHigh  >> 3
 */
#define DMA_STREAM_PRIORITY      3
/* select memory size/width
 options:
 -byte(8 bits)          >> 0
 -half word(16 bits)    >> 1
 -word(32 bits)         >> 2
  */
#define DMA_MEMORY_SIZE          0
/* select peripheral size/width
 options:
 -byte(8 bits)          >> 0
 -half word(16 bits)    >> 1
 -word(32 bits)         >> 2
  */
#define DMA_PERIPHERAL_SIZE          0
/* set memory inrement mode
 options:
 -fixed       >> 0
 -incremented >> 1
  */
#define DMA_MEMORY_INC_MODE          1
/* set peripheral inrement mode
 options:
 -fixed       >> 0
 -incremented >> 1
  */
#define DMA_PERIPHERAL_INC_MODE          1
/* Set circular mode
 options:
 -Enabled   >> 1
 -Disabled  >> 0
  */
#define DMA_CIRCULAR_MODE           0
/* Select Direct Mode or FIFO Mode
 options:
 -Direct Mode   >> 0
 -FIFO Mode    >> 1
  */
#define DMA_DIRECT_OR_FIFO_MODE         1
/*  Select FIFO threshold selection
 options:
 -1/4full  >> 0
 -1/2full  >> 1
 -3/4full  >> 2
 -Full     >> 3
  */
#define DMA_FIFO_THRESHOLD          3




#endif

/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 8/9/2022           */

#ifndef SYSCFG_INTERFACE_H
#define SYSCFG_INTERFACE_H

/*  */
#define SYSCFG_EXTILINE0	0
#define SYSCFG_EXTILINE1	1
#define SYSCFG_EXTILINE2	2
#define SYSCFG_EXTILINE3	3
#define SYSCFG_EXTILINE4	4
#define SYSCFG_EXTILINE5	5
#define SYSCFG_EXTILINE6	6
#define SYSCFG_EXTILINE7	7
#define SYSCFG_EXTILINE8	8
#define SYSCFG_EXTILINE9	9
#define SYSCFG_EXTILINE10	10
#define SYSCFG_EXTILINE11	11
#define SYSCFG_EXTILINE12	12
#define SYSCFG_EXTILINE13	13
#define SYSCFG_EXTILINE14	14
#define SYSCFG_EXTILINE15	15

#define SYSCFG_PORTA	0000
#define SYSCFG_PORTB	0001
#define SYSCFG_PORTC	0010

void SYSCFG_voidSetEXTIPort(u8 Copy_u8EXTILine , u8 Copy_u8Port);

#endif

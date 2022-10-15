/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 10/9/2022           */

#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H

/* Remote Buttons Options  */
#define REMOTE_POWER                       69
#define REMOTE_MODE                        70
#define REMOTE_SILENT                      71
#define REMOTE_PAUSE                       68
#define REMOTE_LEFT                        64
#define REMOTE_RIGHT                       67
#define REMOTE_EQ                          7
#define REMOTE_VOL_LOW                     21
#define REMOTE_VOL_HIGH                    9
#define REMOTE_RPT                         22
#define REMOTE_U_SD                        25
#define REMOTE_ZERO                        13
#define REMOTE_ONE                         12
#define REMOTE_TWO                         24
#define REMOTE_THREE                       94
#define REMOTE_FOUR                        8
#define REMOTE_FIVE                        28
#define REMOTE_SIX                         90
#define REMOTE_SEVEN                       66
#define REMOTE_EIGHT                       82
#define REMOTE_NINE                        74

void IR_voidInit(void);
void IR_voidConfigCharacter(u8 Copy_u8RemoteCharacter,void (*Copyptr)(void));

#endif

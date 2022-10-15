/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 21/8/2022           */

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/* GPIO PORTS definitions */
#define PORTA                 0
#define PORTB                 1
#define PORTC                 2

/* Values definotions */
#define GPIO_HIGH             1
#define GPIO_LOW              0

/* Pins definitions */
#define PIN0                  0
#define PIN1                  1
#define PIN2                  2
#define PIN3                  3
#define PIN4                  4
#define PIN5                  5
#define PIN6                  6
#define PIN7                  7
#define PIN8                  8
#define PIN9                  9
#define PIN10                 10
#define PIN11                 11
#define PIN12                 12
#define PIN13                 13
#define PIN14                 14
#define PIN15                 15

/* MODES definitions */
#define GPIO_GP_OUTPUT_PP_LSPEED                        0b0100000
#define GPIO_GP_OUTPUT_PP_PU_LSPEED                     0b0100001
#define GPIO_GP_OUTPUT_PP_PD_LSPEED                     0b0100010
#define GPIO_GP_OUTPUT_OD_LSPEED                        0b0110000
#define GPIO_GP_OUTPUT_OD_PU_LSPEED                     0b0110001
#define GPIO_GP_OUTPUT_OD_PD_LSPEED                     0b0110010

#define GPIO_GP_OUTPUT_PP_MSPEED                        0b0100100
#define GPIO_GP_OUTPUT_PP_PU_MSPEED                     0b0100101
#define GPIO_GP_OUTPUT_PP_PD_MSPEED                     0b0100110
#define GPIO_GP_OUTPUT_OD_MSPEED                        0b0110100
#define GPIO_GP_OUTPUT_OD_PU_MSPEED                     0b0110101
#define GPIO_GP_OUTPUT_OD_PD_MSPEED                     0b0110110

#define GPIO_GP_OUTPUT_PP_HSPEED                        0b0101000
#define GPIO_GP_OUTPUT_PP_PU_HSPEED                     0b0101001
#define GPIO_GP_OUTPUT_PP_PD_HSPEED                     0b0101010
#define GPIO_GP_OUTPUT_OD_HSPEED                        0b0111000
#define GPIO_GP_OUTPUT_OD_PU_HSPEED                     0b0111001
#define GPIO_GP_OUTPUT_OD_PD_HSPEED                     0b0111010

#define GPIO_GP_OUTPUT_PP_VHSPEED                       0b0101100
#define GPIO_GP_OUTPUT_PP_PU_VHSPEED                    0b0101101
#define GPIO_GP_OUTPUT_PP_PD_VHSPEED                    0b0101110
#define GPIO_GP_OUTPUT_OD_VHSPEED                       0b0111100
#define GPIO_GP_OUTPUT_OD_PU_VHSPEED                    0b0111101
#define GPIO_GP_OUTPUT_OD_PD_VHSPEED                    0b0111110

#define GPIO_AF_PP_LSPEED                               0b1000000
#define GPIO_AF_PP_PU_LSPEED                            0b1000001
#define GPIO_AF_PP_PD_LSPEED                            0b1000010
#define GPIO_AF_OD_LSPEED                               0b1010000
#define GPIO_AF_OD_PU_LSPEED                            0b1010001
#define GPIO_AF_OD_PD_LSPEED                            0b1010010

#define GPIO_AF_PP_MSPEED                               0b1000100
#define GPIO_AF_PP_PU_MSPEED                            0b1000101
#define GPIO_AF_PP_PD_MSPEED                            0b1000110
#define GPIO_AF_OD_MSPEED                               0b1010100
#define GPIO_AF_OD_PU_MSPEED                            0b1010101
#define GPIO_AF_OD_PD_MSPEED                            0b1010110

#define GPIO_AF_PP_HSPEED                               0b1001000
#define GPIO_AF_PP_PU_HSPEED                            0b1001001
#define GPIO_AF_PP_PD_HSPEED                            0b1001010
#define GPIO_AF_OD_HSPEED                               0b1011000
#define GPIO_AF_OD_PU_HSPEED                            0b1011001
#define GPIO_AF_OD_PD_HSPEED                            0b1011010

#define GPIO_AF_PP_VHSPEED                              0b1001100
#define GPIO_AF_PP_PU_VHSPEED                           0b1001101
#define GPIO_AF_PP_PD_VHSPEED                           0b1001110
#define GPIO_AF_OD_VHSPEED                              0b1011100
#define GPIO_AF_OD_PU_VHSPEED                           0b1011101
#define GPIO_AF_OD_PD_VHSPEED                           0b1011110

#define GPIO_INPUT_FLOUTING                             0b0000000
#define GPIO_INPUT_PU                                   0b0000001
#define GPIO_INPUT_PD                                   0b0000010

#define GPIO_INPUT_OUTPUT_ANALOG                        0b1100000




void MGPIO_voidSetPinMode(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode);
void MGPIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);
u8 MGPIO_voidGetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin);


#endif

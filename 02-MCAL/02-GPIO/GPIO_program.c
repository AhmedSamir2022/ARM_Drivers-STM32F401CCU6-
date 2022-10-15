/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 21/8/2022           */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void MGPIO_voidSetPinMode(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
	case PORTA:
		GPIOA->MODER &= ~((0b11) << (Copy_u8Pin * 2));
		GPIOA->MODER |= (((Copy_u8Mode >> 5) & 0b0000011) << (Copy_u8Pin * 2));
		GPIOA->OTYPER &= ~((1) << Copy_u8Pin);
		GPIOA->OTYPER |= (((Copy_u8Mode >> 4) & 0b0000001) << Copy_u8Pin);
		GPIOA->OSPEEDR &= ~((0b11) << (Copy_u8Pin * 2));
		GPIOA->OSPEEDR |= (((Copy_u8Mode >> 2) & 0b0000011) << (Copy_u8Pin * 2));
		GPIOA->PUPDR &= ~((0b11) << (Copy_u8Pin * 2));
		GPIOA->PUPDR |= ((Copy_u8Mode & 0b0000011) << (Copy_u8Pin * 2));
		break;
	case PORTB:
		GPIOB->MODER &= ~((0b11) << (Copy_u8Pin * 2));
		GPIOB->MODER |= (((Copy_u8Mode >> 5) & 0b0000011) << (Copy_u8Pin * 2));
		GPIOB->OTYPER &= ~((1) << Copy_u8Pin);
		GPIOB->OTYPER |= (((Copy_u8Mode >> 4) & 0b0000001) << Copy_u8Pin);
		GPIOB->OSPEEDR &= ~((0b11) << (Copy_u8Pin * 2));
		GPIOB->OSPEEDR |= (((Copy_u8Mode >> 2) & 0b0000011) << (Copy_u8Pin * 2));
		GPIOB->PUPDR &= ~((0b11) << (Copy_u8Pin * 2));
		GPIOB->PUPDR |= ((Copy_u8Mode & 0b0000011) << (Copy_u8Pin * 2));
		break;
	case PORTC:
		GPIOC->MODER &= ~((0b11) << (Copy_u8Pin * 2));
		GPIOC->MODER |= (((Copy_u8Mode >> 5) & 0b0000011) << (Copy_u8Pin * 2));
		GPIOC->OTYPER &= ~((1) << Copy_u8Pin);
		GPIOC->OTYPER |= (((Copy_u8Mode >> 4) & 0b0000001) << Copy_u8Pin);
		GPIOC->OSPEEDR &= ~((0b11) << (Copy_u8Pin * 2));
		GPIOC->OSPEEDR |= (((Copy_u8Mode >> 2) & 0b0000011) << (Copy_u8Pin * 2));
		GPIOC->PUPDR &= ~((0b11) << (Copy_u8Pin * 2));
		GPIOC->PUPDR |= ((Copy_u8Mode & 0b0000011) << (Copy_u8Pin * 2));
		break;
	}
}

void MGPIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case PORTA:
				  if(Copy_u8Value == GPIO_HIGH)
				  {
					  GPIOA->ODR |= (1 << Copy_u8Pin);
				  }
				  else if(Copy_u8Value == GPIO_LOW)
				  {
					  GPIOA->ODR &= ~(1 << Copy_u8Pin);  //Reset bit to zero
					  GPIOA->ODR |= (0 << Copy_u8Pin);
				  }
				  break;
		case PORTB:
				  if(Copy_u8Value == GPIO_HIGH)
				  {
					  GPIOB->ODR |= (1 << Copy_u8Pin);
				  }
				  else if(Copy_u8Value == GPIO_LOW)
				  {
					  GPIOB->ODR &= ~(1 << Copy_u8Pin);  //Reset bit to zero
					  GPIOB->ODR |= (0 << Copy_u8Pin);
				  }
				  break;
		case PORTC:
				  if(Copy_u8Value == GPIO_HIGH)
				  {
					  GPIOC->ODR |= (1 << Copy_u8Pin);
				  }
				  else if(Copy_u8Value == GPIO_LOW)
				  {
					  GPIOC->ODR &= ~(1 << Copy_u8Pin);  //Reset bit to zero
					  GPIOC->ODR |= (0 << Copy_u8Pin);
				  }
				  break;
	}
}

u8 MGPIO_voidGetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 Local_u8ReturnValue = 0;
	switch(Copy_u8Port)
	{
		case PORTA:
                  Local_u8ReturnValue = ((GPIOA->IDR >> Copy_u8Pin) & 1);
				  break;
		case PORTB:
                  Local_u8ReturnValue = ((GPIOB->IDR >> Copy_u8Pin) & 1);
				  break;
		case PORTC:
                  Local_u8ReturnValue = ((GPIOC->IDR >> Copy_u8Pin) & 1);
				  break;
	}
	return Local_u8ReturnValue;
}

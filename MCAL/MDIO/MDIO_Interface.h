/*
 * MDIO_INTERFACE.h
 *
 *  Created on: Feb 6, 2023
 *      Author: norha
 */

#ifndef MDIO_MDIO_INTERFACE_H_
#define MDIO_MDIO_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"

#define MDIO_PORTA 0
#define MDIO_PORTB 1
#define MDIO_PORTC 2
#define MDIO_PORTD 3

#define Null 0

#define PinHigh 1
#define PinLow  0

#define PinOutput 1
#define PinInput 0

#define PortHigh 255
#define PortLOW  0
#define PortOutput 255
#define PortInput 0
typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}Pin_t;

/*Function Prototypes */
void MDIO_SetPortDirection(u8 Copy_u8PortNumber ,u8 Copy_u8PortDirection);
void MDIO_SetPortValue(u8 Copy_u8PortNumber,u8 Copy_u8PortValue);

void MDIO_ReadPin(u8 Copy_u8PortNumber ,u8 Copy_u8PinDirection,u8 * p_u8PortReading);
void MDIO_ReadPort(u8 Copy_u8PortNumber,u8 * p_u8PortReading);

void MDIO_SetPinDirection(u8 Copy_u8PortNumber ,u8 Copy_u8PinDirection,u8 Copy_u8PinNumber);
void MDIO_SetPinValue(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8PinValue);
void MDIO_TogglePin(u8 Copy_u8PinNumber, u8 Copy_PortNumber);
void MDIO_SetNibbleValue(u8 Copyu8PinStart, u8 Copyu8PortNumber, u8 Copyu8Value);


#endif /* MDIO_MDIO_INTERFACE_H_ */

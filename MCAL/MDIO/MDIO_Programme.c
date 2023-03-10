/*
 * MDIO_Programme.c
 *
 *  Created on: Feb 6, 2023
 *      Author: norha
 */
#include "MDIO_Interface.h"
#include "MDIO_Private.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

void MDIO_SetPortDirection(u8 Copy_u8PortNumber ,u8 Copy_u8PortDirection)
{
	if ((Copy_u8PortDirection==PortOutput||Copy_u8PortDirection==PortInput))
	{
		//Handling values
		switch (Copy_u8PortNumber)
		{ case MDIO_PORTA:
			DDRA=Copy_u8PortDirection;
			break;
		case MDIO_PORTB:
					DDRB=Copy_u8PortDirection;
					break;
		case MDIO_PORTC:
					DDRC=Copy_u8PortDirection;
					break;
		case MDIO_PORTD:
					DDRD=Copy_u8PortDirection;
					break;
		default : /*Wrong Port Number Passed*/
		           break;
		}
	}
	else
	{
		/*Invalid PortNumber*/
	}

}
void MDIO_SetPortValue(u8 Copy_u8PortNumber,u8 Copy_u8PortValue)
{
	if ((Copy_u8PortValue==PortHigh||Copy_u8PortValue==PortLOW))
		{
			//Handling values
			switch (Copy_u8PortNumber)
			{ case MDIO_PORTA:
				DDRA=Copy_u8PortValue;
				break;
			case MDIO_PORTB:
						DDRB=Copy_u8PortValue;
						break;
			case MDIO_PORTC:
						DDRC=Copy_u8PortValue;
						break;
			case MDIO_PORTD:
						DDRD=Copy_u8PortValue;
						break;
			default : /*Wrong Port Number Passed*/
			           break;
			}
		}
		else
		{
			/*Invalid portValue */
		}

}

void MDIO_ReadPin(u8 Copy_u8PortNumber ,u8 Copy_u8PinNumber,u8 * p_u8PortReading)
{
	if((Copy_u8PinNumber>=0||Copy_u8PinNumber<8))
	{
		switch(Copy_u8PortNumber){
		case MDIO_PORTA:
				 *p_u8PortReading=GET_BIT(PINA,Copy_u8PinNumber);

			break;
		case MDIO_PORTB:
				*p_u8PortReading=GET_BIT(PINA,Copy_u8PinNumber);

			break;
		case MDIO_PORTC:
				 *p_u8PortReading=GET_BIT(PINA,Copy_u8PinNumber);

			break;
		case MDIO_PORTD:
				*p_u8PortReading=GET_BIT(PINA,Copy_u8PinNumber);

			break;
		}
	}
	else
	{
		/*Invalid Pin Number*/
	}
}
void MDIO_ReadPort(u8 Copy_u8PortNumber,u8 * p_u8PortReading)
{
	if(p_u8PortReading!=Null)
	{
		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA:
			*p_u8PortReading=PINA;
			break;
		case MDIO_PORTB:
			*p_u8PortReading=PINB;
			break;
		case MDIO_PORTC:
			*p_u8PortReading=PINC;
			break;
		case MDIO_PORTD:
			*p_u8PortReading=PIND;
			break;
		}
	}
	else
	{
		/*Invalid Port Number*/
	}
}
void MDIO_SetPinDirection(u8 Copy_u8PortNumber ,u8 Copy_u8PinDirection,u8 Copy_u8PinNumber)
{
	if((Copy_u8PinNumber>=0||Copy_u8PinNumber<8))
			{
				switch(Copy_u8PortNumber)
				{
					case MDIO_PORTA:
						if(Copy_u8PinDirection==PinOutput)
						{
							SET_BIT(DDRA,Copy_u8PinNumber);
						}
						else if(Copy_u8PinDirection==PinInput)
						{
							CLR_BIT(DDRA,Copy_u8PinNumber);
						}
						else
						{
										//Invalid Pin Direction
						}
					break;
					case MDIO_PORTB:
						if(Copy_u8PinDirection==PinOutput)
						{
							SET_BIT(DDRB,Copy_u8PinNumber);
						}
						else if(Copy_u8PinDirection==PinInput)
						{
							CLR_BIT(DDRB,Copy_u8PinNumber);
						}
						else
						{
										//Invalid Pin Direction
						}
					break;
					case MDIO_PORTC:
						if(Copy_u8PinDirection==PinOutput)
						{
							SET_BIT(DDRC,Copy_u8PinNumber);
						}
						else if(Copy_u8PinDirection==PinInput)
						{
							CLR_BIT(DDRC,Copy_u8PinNumber);
						}
						else
						{
										//Invalid Pin Direction
						}
					break;
					case MDIO_PORTD:
						if(Copy_u8PinDirection==PinOutput)
						{
							SET_BIT(DDRD,Copy_u8PinNumber);
						}
						else if(Copy_u8PinDirection==PinInput)
						{
							CLR_BIT(DDRD,Copy_u8PinNumber);
						}
						else
						{
										//Invalid Pin Direction
						}
					break;

				}
			}
	else
		{
		/*Invalid Pin Value */
		}
}
void MDIO_SetPinValue(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8PinValue)
{
	if((Copy_u8PinNumber>=0&&Copy_u8PinNumber<8))
			{
				switch(Copy_u8PortNumber)
				{
					case MDIO_PORTA:
						if(Copy_u8PinValue==PinHigh)
						{
							SET_BIT(PORTA,Copy_u8PinNumber);
						}
						else if(Copy_u8PinValue==PinLow)
						{
							CLR_BIT(PORTA,Copy_u8PinNumber);
						}
						else
									{
										//Invalid Pin Value
									}
					break;
					case MDIO_PORTB:
						if(Copy_u8PinValue==PinHigh)
						{
							SET_BIT(PORTB,Copy_u8PinNumber);
						}
						else if(Copy_u8PinValue==PinLow)
						{
							CLR_BIT(PORTB,Copy_u8PinNumber);
						}
						else
									{
										//Invalid Pin Value
									}
					break;
					case MDIO_PORTC:
						if(Copy_u8PinValue==PinHigh)
						{
							SET_BIT(PORTC,Copy_u8PinNumber);
						}
						else if(Copy_u8PinValue==PinLow)
						{
							CLR_BIT(PORTC,Copy_u8PinNumber);
						}
						else
						{
							//Invalid Pin Value
						}
					break;
					case MDIO_PORTD:
						if(Copy_u8PinValue==PinHigh)
						{
							SET_BIT(PORTD,Copy_u8PinNumber);
						}
						else if(Copy_u8PinValue==PinLow)
						{
							CLR_BIT(PORTD,Copy_u8PinNumber);
						}
						else
						{
							//Invalid Pin Value
						}
					break;

				}
			}
	else
		{
		/*Invalid Pin Value */
		}
}

void MDIO_TogglePin(u8 Copy_u8PinNumber, u8 Copy_PortNumber)
{
	if((Copy_u8PinNumber>=0||Copy_u8PinNumber>8))
	{
		switch(Copy_PortNumber)
		{
		case MDIO_PORTA:
			TOGGLE_BIT(PORTA,Copy_u8PinNumber);
			break;
		case MDIO_PORTB:
			TOGGLE_BIT(PORTB,Copy_u8PinNumber);
			break;
		case MDIO_PORTC:
			TOGGLE_BIT(PORTC,Copy_u8PinNumber);
			break;
		case MDIO_PORTD:
			TOGGLE_BIT(PORTD,Copy_u8PinNumber);
			break;

		}
	}
	else
	{
		/*Invalid Pin Number */
	}
}
void MDIO_SetNibbleValue(u8 Copyu8PinStart, u8 Copyu8PortNumber, u8 Copyu8Value)
{
	u8 Loc_u8Value=Copyu8Value;
	Loc_u8Value=((Loc_u8Value&0x0F)<<Copyu8PinStart);
	if(Copyu8PinStart>=0&&Copyu8PinStart<=4)
	{
		switch (Copyu8PortNumber)
		{
		case MDIO_PORTA:
			PORTA&=(~((0X0F)<<Copyu8PinStart));
			PORTA|=Loc_u8Value;
			break;
		case MDIO_PORTB:
			PORTB&=(~((0X0F)<<Copyu8PinStart));
			PORTB|=Loc_u8Value;
			break;
		case MDIO_PORTC:
			PORTC&=(~((0X0F)<<Copyu8PinStart));
			PORTC|=Loc_u8Value;
			break;
		case MDIO_PORTD:
			PORTD&=(~((0X0F)<<Copyu8PinStart));
			PORTD|=Loc_u8Value;
			break;
		}
	}

}


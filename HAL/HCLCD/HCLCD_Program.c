/*
 * HCLCD_Program.c
 *
 *  Created on: Oct 1, 2022
 *      Author: norha
 */
#include"../../MCAL/MDIO/MDIO_Interface.h"

#include"util/delay.h"
#include "../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"HCLCD_Interface.h"
#include"HCLCD_Config.h"


void HCLCD_WriteCommand4Bit(u8 Copy_u8Command)
{
	//Set RW to Zero
	MDIO_SetPinValue(CONTROL_PORT, RW, PinLow);

	//Set RS to Zero ==> to indicate a Command
	MDIO_SetPinValue(CONTROL_PORT, RS, PinLow);

	//Set High Nibble Value of the Command
	MDIO_SetNibbleValue(HCLCD_PIN_START, DATA_PORT, Copy_u8Command>>4);
	//Send the Falling Edge
	MDIO_SetPinValue(CONTROL_PORT, E, PinHigh);
	_delay_ms(2);
	MDIO_SetPinValue(CONTROL_PORT, E, PinLow);

	//Send The Lower Nibble
	MDIO_SetNibbleValue(HCLCD_PIN_START, DATA_PORT, Copy_u8Command);

	//Send the Falling Edge
	MDIO_SetPinValue(CONTROL_PORT, E, PinHigh);
	_delay_ms(2);
	MDIO_SetPinValue(CONTROL_PORT, E, PinLow);
}

void HCLCD_Init4Bit()
{
	_delay_ms(30);

	u8 Loc_u8Counter=0;

	//Set Direction of Data the used pins
	for(Loc_u8Counter=HCLCD_PIN_START;Loc_u8Counter<(HCLCD_PIN_START+4);Loc_u8Counter++)
	{
		MDIO_SetPinDirection(DATA_PORT, PinOutput, Loc_u8Counter);
	}

	//Set Direction of the Control Pins
	MDIO_SetPinDirection(CONTROL_PORT, PinOutput, RS);
	MDIO_SetPinDirection(CONTROL_PORT, PinOutput, RW);
	MDIO_SetPinDirection(CONTROL_PORT, PinOutput, E);


	/*
	 * Start of the initialization sequence
	 */
	//Send Function Set Command

	//1-Sending High Nibble of the Function Set Command

	MDIO_SetNibbleValue(HCLCD_PIN_START,DATA_PORT,FUNCTION_SET_MODE_COMMAND>>4);

	//Send the Falling Edge
	MDIO_SetPinValue(CONTROL_PORT, E, PinHigh);
	_delay_ms(2);
	MDIO_SetPinValue(CONTROL_PORT, E, PinLow);


	//2-Sending Function Set Command

	HCLCD_WriteCommand4Bit(FUNCTION_SET_MODE_COMMAND);

	//Send Display On/Off command
	_delay_ms(1);
	HCLCD_WriteCommand4Bit(DISPALY_ON_OFF_COMMAND);

	//Display Clear Mode
	_delay_ms(1);
	HCLCD_WriteCommand4Bit(DISPALY_ClEAR_COMMAND);

	//Entry Mode
	_delay_ms(2);
	HCLCD_WriteCommand4Bit(ENTRY_MODE_COMMAND);
}

void HCLCD_WriteChar4Bit(u8 Copy_u8Data)
{
	//Set RW to Zero
	MDIO_SetPinValue(CONTROL_PORT, RW, PinLow);

	//Set RS to One ==> to indicate a Data
	MDIO_SetPinValue(CONTROL_PORT, RS, PinHigh);

	//Set High Nibble Value of the Command
	MDIO_SetNibbleValue(HCLCD_PIN_START,DATA_PORT,Copy_u8Data>>4);

	//Send the Falling Edge
	MDIO_SetPinValue(CONTROL_PORT, E, PinHigh);
	_delay_ms(2);
	MDIO_SetPinValue(CONTROL_PORT, E, PinLow);

	//Send The Lower Nibble
MDIO_SetNibbleValue(HCLCD_PIN_START, DATA_PORT, Copy_u8Data);
	//Send the Falling Edge
	MDIO_SetPinValue(CONTROL_PORT, E, PinHigh);
	_delay_ms(2);
	MDIO_SetPinValue(CONTROL_PORT, E, PinLow);
}

void HCLCD_SetCursorPosition(u8 Copy_u8LineNumber,u8 Copy_u8PositionNumber)
{
if((Copy_u8LineNumber==HCLCD_LINE_0)||(Copy_u8LineNumber==HCLCD_LINE_1))
{
	if(Copy_u8PositionNumber<16)
	{
		if(Copy_u8LineNumber==HCLCD_LINE_0)
		{
			HCLCD_WriteCommand4Bit(Copy_u8PositionNumber+HCLCD_LINE0_OFFSET);
		}
		else
		{
			HCLCD_WriteCommand4Bit(Copy_u8PositionNumber+HCLCD_LINE1_OFFSET);
		}
	}
}
else
{
	//Wrong Line Chosen
}
}
void HLCD_WriteString4Bit (u8 *ptr_u8String)
{ u8 loc_u8it =0;
 for (loc_u8it=0;ptr_u8String[loc_u8it]!=Null;loc_u8it++)
 {
	 //set RS to 1 TO INDICATE a data
		MDIO_SetPinValue(CONTROL_PORT, RS, PinHigh);

	 		//set RW TO 0
	 		MDIO_SetPinValue(CONTROL_PORT, RW, PinLow);

	 		// set high nibble value of the command
	 		MDIO_SetNibbleValue(HCLCD_PIN_START, DATA_PORT, ptr_u8String[loc_u8it] >>4);
	 		//set falling edge
	 		MDIO_SetPinValue(CONTROL_PORT, E, PinHigh);
	 	      _delay_ms(2);
	 	 	MDIO_SetPinValue(CONTROL_PORT, E, PinLow);

	 	     // set low nibble value of the command

        MDIO_SetNibbleValue(HCLCD_PIN_START, DATA_PORT, ptr_u8String[loc_u8it]);
	 	      //set falling edge
	 		MDIO_SetPinValue(CONTROL_PORT, E, PinHigh);
	 	      _delay_ms(2);
	 	 	MDIO_SetPinValue(CONTROL_PORT, E, PinLow);

 }

	}
void HCLCD_WriteNumber(u32 Copy_u32Number)
{
	/*Define an array of 10 elements to hold the number digits
	size is 10 because larger number in u32 is 4,294,967,295
	which is 10 digits
	 */
	u8 Loc_u8Arr_Digits[10];

	/*Define a Local Counter to traverse the array*/
	u8 Loc_Counter=0;

	/*Check on the upcoming number*/
	if(Copy_u32Number>0)
	{
		/*Parsing the number into the array*/
		while(Copy_u32Number!=0) //Exit Condition means number is done parsing
		{
			//Extract the Least Significant Digit and Put it in the
			//Array
			Loc_u8Arr_Digits[Loc_Counter]=Copy_u32Number%10 ;

			//Removing the Extracted digit from the number
			Copy_u32Number=Copy_u32Number/10 ;

			//Increasing the counter so the digits are saved in next array element
			Loc_Counter++;

		}

		//Here the parsing is finished and the digits are saved
		//in the array but backwards

		//Take Care Loc_forCounter is signed
		//because we are decrementing it
		s8 Loc_forCounter;
		for(Loc_forCounter=Loc_Counter-1;Loc_forCounter>=0;Loc_forCounter--)
		{
			//Write the digits to the screen in their right order
			//Notice the addition of the number to the ASCII Code
			//of the number 0 because our Function takes ASCII of character
			//to Print on the LCD
			HCLCD_WriteChar4Bit(Loc_u8Arr_Digits[Loc_forCounter]+'0');
		}

	}
	else
	{
		/*if the number is zero so we have to send ASCII Code of Zero*/
		HCLCD_WriteChar4Bit('0');
	}

}


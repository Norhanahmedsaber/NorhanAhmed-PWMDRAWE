/*
 * main.c
 *
 *  Created on: Feb 14, 2023
 *      Author: norha
 */
#include "MCAL/MDIO/MDIO_Interface.h"
#include "HAL/HCLCD/HCLCD_Interface.h"
#include "MCAL/MTIMER/MTIMER_Interface.h"
#include "MCAL/MTIMER/MTIMER_Private.h"

f32 static GLOBALU16_ONTIME=0;
f32 static GLOBALU16_TOTALTIME=0;
u8  static GLOBAL_U8COUNTER=0;
u8 static LOCAL_U8NOOVERFLOW=0 ;
f32 static GLOBAL_f32Freq;
f32 static GLOBAL_F32DUTY;
u8  static x;
u16 static y;
void ISR_TIMERSTART(void)
{
if(GLOBAL_U8COUNTER==0){
	MTIMER0_Init();
	GLOBAL_U8COUNTER++;
}else if(GLOBAL_U8COUNTER==1)
{

 y=TCNT0+(LOCAL_U8NOOVERFLOW*256);//TCNT0(no.ofticks)+km maraoverflow*256
GLOBALU16_ONTIME=(y*(1/(1000000.0/64.0)));//Y*TICKTIME
GLOBAL_U8COUNTER++;
}else if (GLOBAL_U8COUNTER==2)
{
  x=TCNT0+(LOCAL_U8NOOVERFLOW*255);
 GLOBALU16_TOTALTIME=x*(1/(1000000.0/64.0));
 GLOBAL_U8COUNTER=0;
}
}
void ISR_OVERFLOW(void)
{
	LOCAL_U8NOOVERFLOW++;
	}
int main()
{
	GLOBAL_F32DUTY=GLOBALU16_ONTIME/GLOBALU16_TOTALTIME;
	 GLOBAL_f32Freq=1/GLOBALU16_TOTALTIME;
	 GLOBAL_F32DUTY=GLOBAL_F32DUTY*100;
	MTIMER0_OVERFLOW_CALLBACK(ISR_OVERFLOW);
	INTERRUPT_Set0CallBack(ISR_TIMERSTART);
	HCLCD_Init4Bit();
	HLCD_WriteString4Bit("freq");
	HCLCD_WriteNumber(GLOBAL_f32Freq);
	//HCLCD_WriteNumber(100);
	HLCD_WriteString4Bit("Duty");
	//HCLCD_WriteNumber(50);
	HCLCD_WriteNumber(GLOBAL_F32DUTY);
	HLCD_WriteString4Bit("%");
	HCLCD_SetCursorPosition( HCLCD_LINE_1 , 1);
	u8 LOC_u8Counter=0;
	for(LOC_u8Counter=0;LOC_u8Counter<4;LOC_u8Counter++)
	{
	HLCD_WriteString4Bit("_");
	HLCD_WriteString4Bit("|");
	HLCD_WriteString4Bit("-");
	HLCD_WriteString4Bit("|");
	}
	return 0;
}

/*
 * MTIMER_Interface.h
 *
 *  Created on: Oct 28, 2022
 *      Author: norha
 */

#ifndef MCAL_MTIMER_MTIMER_INTERFACE_H_
#define MCAL_MTIMER_MTIMER_INTERFACE_H_



/*Function Prototypes*/
void MTIMER0_Init();

void MTIMER0_SetPreload(u8 Copy_u8Preload);

void MTIMER0_SetCTC(u8 Copy_u8OCR);

void MTIMER0_OVERFLOW_CALLBACK(void(*Ptr_OverflowApp)(void));


void MTIMER0_CTC_CALLBACK(void(*Ptr_CTCApp)(void));

void MTIOMER0_DUTY_CYCLE(u8  Copyu8_DutyCycle);

#endif /* MCAL_MTIMER_MTIMER_INTERFACE_H_ */

/*
 * MEXTI_Interface.h
 *
 *  Created on: Oct 21, 2022
 *      Author: norha
 */

#ifndef MCAL_MEXTI_MEXTI_INTERFACE_H_
#define MCAL_MEXTI_MEXTI_INTERFACE_H_

/*Function Prototype*/
void MEXTI0_Init();
void(*INTERRUPT_CallBack)(void); //pointer to function
void INTERRUPT_Set0CallBack(void(*copy_ptr)(void))

//call back function
void __vector_1(void)__attribute((signal));
void __vector_1(void);
/*
void MEXTI1_Init();
void MEXTI2_Init();
*/

//void MEXTI_SetSenseControl(u8 Copy_u8Interrupt_ID, u8 Copy_u8Mode)


#endif /* MCAL_MEXTI_MEXTI_INTERFACE_H_ */

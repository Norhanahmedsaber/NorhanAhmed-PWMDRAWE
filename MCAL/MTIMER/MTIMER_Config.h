/*
 * MTIMER_Config.h
 *
 *  Created on: Oct 28, 2022
 *      Author: norha
 */

#ifndef MCAL_MTIMER_MTIMER_CONFIG_H_
#define MCAL_MTIMER_MTIMER_CONFIG_H_

/*
 * Options for TIMER_MODE
 *1-TIMER_NORMAL_MODE
 *2-TIMER_PWM_PHASE_CORRECT_MODE
 *3-TIMER_CTC_MODE
 *4-TIMER_FAST_PWM_MODE
 */
#define TIMER0_MODE TIMER_FAST_PWM_MODE


/*
 * Options For OC0 Pin:
 *1-OC0_PIN_DISCONNECTED
 *1-OC0_PIN_TOGGLE
 *1-OC0_PIN_CLEARED
 *1-OC0_PIN_SET
 */
#define TIMER0_OC0_MODE OC0_PIN_TOGGLE

/*
 * Options For CLOCK Pin:
 *1-NO_CLOCK
 *1-SYSTEM_CLOCK
 *1-PRESCALAR_OVER_8
 *1-PRESCALAR_OVER_64
 *1-PRESCALAR_OVER_256
 *1-PRESCALAR_OVER_1024
 *1-EXTERNAL_CLOCK_FALLING_EDGE
 *1-EXTERNAL_CLOCK_RISING_EDGE
 */
#define TIMER0_CLOCK_SOURCE PRESCALAR_OVER_64


/*
 * Options For TOV Interrupt:
 *1-NORMAL_MODE_INTERRUPT_DISABLED
 *1-NORMAL_MODE_INTERRUPT_ENABLED
 */
#define TIMER0_NORMAL_MODE_INTERRUPT_STATE NORMAL_MODE_INTERRUPT_ENABLED

/*
 * Options For CTC Interrupt:
 *1-CTC_MODE_INTERRUPT_DISABLED
 *1-CTC_MODE_INTERRUPT_ENABLED
 */
#define TIMER0_CTC_MODE_INTERRUPT_STATE CTC_MODE_INTERRUPT_ENABLED


/**
 * Options For Fast PWM
 *1-FAST_PWM_OC0_DISCONNECTED
 *1-FAST_PWM_OC0_NON_INVERTING
 *1-FAST_PWM_OC0_INVERTING
 */

#define TIMER0_FAST_PWM_WAVE_MODE FAST_PWM_OC0_NON_INVERTING



/**
 * Options For PHASE CORRECT PWM
 *1-PHASE_CORRECT_PWM_OC0_DISCONNECTED
 *1-PHASE_CORRECT_PWM_OC0_NON_INVERTING
 *1-PHASE_CORRECT_PWM_OC0_INVERTING
 */

#define TIMER0_PHASE_CORRECT_PWM_WAVE_MODE PHASE_CORRECT_PWM_OC0_NON_INVERTING


#endif /* MCAL_MTIMER_MTIMER_CONFIG_H_ */

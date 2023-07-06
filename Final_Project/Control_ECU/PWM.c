#include "common_macros.h"
#include "gpio.h"
#include "PWM.h"
#include <avr/io.h>

void PWM_Timer0_Start(uint8 duty_cycle)
{
	/*TIM0 as Fast PWM mode*/
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	/*NON_Inverting mode*/
	CLEAR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	
	/*Prescaler=Fcpu/8*/
	CLEAR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
	
	TCNT0 =0;

	OCR0 = duty_cycle;
	
	/*Setting OC0 output pin*/
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);
}

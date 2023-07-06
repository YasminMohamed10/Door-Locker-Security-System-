 /******************************************************************************
 *
 * Module: TIMER_1
 *
 * File Name: TIM1.c
 *
 * Description: Source file for the Timer_1 driver
 *
 * Author: Yasmin Mohamed
 *
 *******************************************************************************/
 
 #include "common_macros.h"
 #include "gpio.h"
 #include "TIM1.h"
 #include <avr/io.h>
 #include <avr/interrupt.h>
 
 /*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

static volatile void (*g_callBackPtr)(void) = NULL_PTR;

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/
 
 /*Channel A*/
#if TIMER1_CHANNEL_NUM==0

ISR(TIMER1_COMPA_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)(); 
	}
}

/*Channel B*/
#else
	
ISR(TIMER1_COMPB_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		
		(*g_callBackPtr)();
	}
}
#endif

 /*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
 
 void Timer1_init(const Timer1_ConfigType * Config_Ptr)
 {
	/*Prescaler*/
	TCCR1B = (TCCR1B & 0xF8) | ((Config_Ptr -> prescaler) & 0x07);
	
	TCNT1= Config_Ptr-> initial_value;
	
	if(Config_Ptr -> mode == TIMER1_CMP)
	{
		if(TIMER1_CHANNEL_NUM==0)
		{
			SET_BIT(TCCR1B, WGM12);
			SET_BIT(TIMSK, OCIE1A);
			TCCR1A = (TCCR1A & 0x0F) | ((Config_Ptr -> mode) << 6);
			OCR1A= Config_Ptr-> compare_value;
			SET_BIT(TCCR1A,FOC1A);
		}
		else if(TIMER1_CHANNEL_NUM==1)
		{
			SET_BIT(TCCR1B, WGM12);
			SET_BIT(TIMSK, OCIE1B);
			TCCR1A = (TCCR1A & 0x0F) | (((Config_Ptr -> mode) & 0xF0) << 4);
			OCR1B= Config_Ptr-> mode;
			SET_BIT(TCCR1A, FOC1B);
		}
	}
	
	else if(Config_Ptr -> mode == TIMER1_OVF)
	{
		SET_BIT(TIMSK, TOIE1);
	}
	
	
 }
 void Timer1_deInit(void)
 {
	/* Clear All Timer1 Registers */
	TCNT1 = 0;
	OCR1A = 0 ;
	OCR1B = 0 ;
	TCCR1A = 0;
	TCCR1B = 0;
 }
 void Timer1_setCallBack(void(*a_ptr)(void))
 {
	g_callBackPtr = a_ptr; 
 }
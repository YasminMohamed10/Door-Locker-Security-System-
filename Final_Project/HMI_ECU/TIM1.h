 /******************************************************************************
 *
 * Module: TIMER_1
 *
 * File Name: TIM1.h
 *
 * Description: Header file for the Timer_1 driver
 *
 * Author: Yasmin Mohamed
 *
 *******************************************************************************/

#ifndef TIM1_H_
#define TIM1_H_

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
 
 /*Channel 0 for A and Channel 1 for B*/
#define TIMER1_CHANNEL_NUM 0   
 
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
 
 typedef enum
 {
 	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024,F_CPU_External_Falling,F_CPU_External_Rising
 }Timer1_Prescaler;
 
 typedef enum
 {
 	TIMER1_OVF,TIMER1_CMP
 }Timer1_Mode;
  
 typedef struct {
 	uint16 initial_value;
 	uint16 compare_value;
 	Timer1_Prescaler prescaler;
 	Timer1_Mode mode;
 } Timer1_ConfigType;
 
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
 
 void Timer1_init(const Timer1_ConfigType * Config_Ptr);
 void Timer1_deInit(void);
 void Timer1_setCallBack(void(*a_ptr)(void));

#endif
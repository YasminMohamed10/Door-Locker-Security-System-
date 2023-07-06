 /******************************************************************************
 *
 * Module: Buzzer
 *
 * File Name: Buzzer.h
 *
 * Description: Header file for the Buzzer driver
 *
 * Author: Yasmin Mohamed
 *
 *******************************************************************************/

#ifndef BUZZER_H_
#define BUZZER_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define BUZZER_PORT_ID             PORTD_ID
#define BUZZER_PIN_ID              PIN0_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
 
void Buzzer_init(void);
void Buzzer_on(void);
void Buzzer_off(void);


#endif

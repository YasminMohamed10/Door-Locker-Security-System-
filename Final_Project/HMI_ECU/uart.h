 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART AVR driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_

#include "std_types.h"

  
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
 
typedef enum
{
	UART_5_BIT_DATA,UART_6_BIT_DATA,UART_7_BIT_DATA,UART_8_BIT_DATA,UART_9_BIT_DATA=7
}UART_BitData;

typedef enum
{
	UART_NO_PARITY,UART_EVEN_PARITY=2,UART_ODD_PARITY
}UART_Parity;

typedef enum
{
	UART_ONE_STOP_BIT,UART_TWO_STOP_BITS
}UART_StopBit;

typedef struct{
	UART_BitData bit_data; 
	UART_Parity  parity;
	UART_StopBit stop_bit; //Enter value 1 or 2 
	uint32       baud_rate;
}UART_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Functional responsible for Initialize the UART device by:
 * 1. Setup the Frame format like number of data bits, parity bit type and number of stop bits.
 * 2. Enable the UART.
 * 3. Setup the UART baud rate.
 */
void UART_init(const UART_ConfigType * Config_Ptr);

/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const uint8 data);

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8 UART_recieveByte(void);

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const uint8 *Str);

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(uint8 *Str); // Receive until #

#endif /* UART_H_ */

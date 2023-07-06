#include <avr/io.h>
#include <avr/interrupt.h>
#include "std_types.h"
#include "gpio.h"
#include "TIM1.h"
#include "uart.h"
#include "lcd.h"
#include "keypad.h"
#include "HMI.h"
#include <avr/delay.h>

uint8 RecievedPass1[PASSWORD_LENGTH], RecievedPass2[PASSWORD_LENGTH];
uint8 RecieveByte, State, u8_key;

int main()
{
	UART_ConfigType UART_Config ={UART_8_BIT_DATA,UART_ONE_STOP_BIT,UART_NO_PARITY,9600};
	UART_init(&UART_Config);
	LCD_init();
	HMI_CreatePassword(g_Password1);
	HMI_ConfirmPassword(g_Password2);
	State = HMI_CheckifPassMatch(g_Password1,g_Password2);

	if(State == SUCCESS)
	{
		LCD_clearScreen();
		LCD_moveCursor(0,4);
		LCD_displayString("Matched!");
		_delay_ms(20);

		for (uint8 i=0;i<PASSWORD_LENGTH;i++)
		{
			UART_sendByte(g_Password1[i]);
			_delay_ms(20);
		}
		HMI_MainOptions();

		u8_key= KEYPAD_getPressedKey();
		_delay_ms(20);
		switch(u8_key)
		{
		case '+':
			LCD_clearScreen();
			HMI_EnterPassword(g_Password3);

			for (uint8 i=0;i<PASSWORD_LENGTH;i++)
			{
				UART_sendByte(g_Password3[i]);
				_delay_ms(20);
			}

			if(HMI_CheckifPassMatch(g_Password2,g_Password3)==SUCCESS)
			{
				LCD_clearScreen();
				LCD_displayString("Door is opening");
			}
			else
			{
				LCD_clearScreen();
				LCD_displayString("Wrong Pass");
				_delay_ms(50);
				LCD_clearScreen();
				LCD_displayString("Try again!");
				_delay_ms(50);
			}
			break;
		}
	}
	else
	{
		LCD_clearScreen();
		LCD_displayString("Not Matched!");
	}

	while(1)
	{

	}
}



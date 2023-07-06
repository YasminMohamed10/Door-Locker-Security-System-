#include "HMI.h"
#include "uart.h"
#include "lcd.h"
#include "keypad.h"
#include <avr/delay.h>

/**********Global Variables**********/

uint8 u8_key, option;
uint8 EnteredPass[PASSWORD_LENGTH], ReEnteredPass[PASSWORD_LENGTH], Enteredpass[PASSWORD_LENGTH];
uint8 g_savedPass[PASSWORD_LENGTH];
uint8 u8_ticks=0;

/*********Function Implementation*********/

void HMI_CreatePassword(uint8* EnteredPass)
{
	uint8 u8_PressNum_1=1;
	LCD_displayString("Enter Password:");
	LCD_moveCursor(1,0);

	u8_key= KEYPAD_getPressedKey();
	_delay_ms(50);

	if(u8_key<=9 && u8_key>=0)
	{
		LCD_displayString("*");
		EnteredPass[0]= u8_key;
	}

	while(u8_key<=9 && u8_key>=0 && u8_PressNum_1<PASSWORD_LENGTH)
	{
		u8_key= KEYPAD_getPressedKey();
		_delay_ms(50);
		LCD_displayString("*");
		EnteredPass[u8_PressNum_1]= u8_key;
		u8_PressNum_1++;
	}

	u8_key= KEYPAD_getPressedKey();
	_delay_ms(50);

	if(u8_key==ENTER_KEY  && u8_PressNum_1==PASSWORD_LENGTH)
	{
		LCD_clearScreen();
		for (uint8 i=0;i<PASSWORD_LENGTH;i++)
		{
			g_Password1[i]=EnteredPass[i];
			_delay_ms(50);
		}
	}
}
void HMI_ConfirmPassword(uint8* ReEnteredPass)
{
	uint8 u8_PressNum_2=1;
	LCD_clearScreen();
	LCD_displayString("ReEnter Password:");
	LCD_moveCursor(1,0);

	u8_key= KEYPAD_getPressedKey();
	_delay_ms(50);

	if(u8_key<=9 && u8_key>=0)
	{
		LCD_displayString("*");
		ReEnteredPass[0]= u8_key;
	}

	while(u8_key<=9 && u8_key>=0 && u8_PressNum_2<PASSWORD_LENGTH)
	{
		u8_key= KEYPAD_getPressedKey();
		_delay_ms(50);
		LCD_displayString("*");
		ReEnteredPass[u8_PressNum_2]= u8_key;
		u8_PressNum_2++;
	}

	u8_key= KEYPAD_getPressedKey();
	_delay_ms(40);

	if(u8_key==ENTER_KEY && u8_PressNum_2==PASSWORD_LENGTH)
	{
		for (uint8 i=0;i<PASSWORD_LENGTH;i++)
		{
			g_Password2[i]=ReEnteredPass[i];
			_delay_ms(50);
		}
	}
}
uint8 HMI_CheckifPassMatch(uint8* Enter_Pass,uint8* ReEnter_Pass)
{
	uint8 i=0;
	while(i<PASSWORD_LENGTH)
	{
		if(Enter_Pass[i]==ReEnter_Pass[i])

		{
			i++;
		}
		else
		{
			return ERROR;
		}
	}
	return SUCCESS;
}
void HMI_MainOptions(void)
{
	LCD_clearScreen();
	LCD_displayString("+ : Open Door");
	LCD_moveCursor(1,0);
	LCD_displayString("- : Change Pass");
}
void HMI_EnterPassword(uint8* Enteredpass)
{
	uint8 u8_PressNum_1=1;
	LCD_clearScreen();
	LCD_displayString("Welcome Back!");
	_delay_ms(60);
	LCD_clearScreen();
	LCD_displayString("Enter Password:");
	LCD_moveCursor(1,0);

	u8_key= KEYPAD_getPressedKey();
	_delay_ms(40);

	if(u8_key<=9 && u8_key>=0)
	{
		LCD_displayString("*");
		Enteredpass[0]= u8_key;
	}

	while(u8_key<=9 && u8_key>=0 && u8_PressNum_1<PASSWORD_LENGTH)
	{
		u8_key= KEYPAD_getPressedKey();
		_delay_ms(50);
		LCD_displayString("*");
		Enteredpass[u8_PressNum_1]= u8_key;
		u8_PressNum_1++;
	}

	u8_key= KEYPAD_getPressedKey();
	_delay_ms(50);

	if(u8_key==ENTER_KEY  && u8_PressNum_1==PASSWORD_LENGTH)
	{
		LCD_clearScreen();
		for (uint8 i=0;i<PASSWORD_LENGTH;i++)
		{
			g_Password3[i]=Enteredpass[i];
			_delay_ms(50);
		}
	}
}

void OpenDoor(void)
{
	LCD_clearScreen();
	LCD_displayString("Door is opening");
}

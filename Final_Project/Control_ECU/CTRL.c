#include "CTRL.h"
#include "external_eeprom.h"
#include "uart.h"
#include <avr/delay.h>

void Receive_password_from_HMI_ECU (uint8* password)
{
	UART_sendByte(M1_READY);
	while (UART_recieveByte() != M2_READY);
	for (uint8 i=0;i<PASSWORD_LENGTH;i++)
	{
		password[i]=UART_recieveByte();
		_delay_ms(50);
	}
}

void Save_passwordToEEPROM (uint8 *password)
{
	uint8 i;
	for(i=0;i<PASSWORD_LENGTH;i++)
	{
		EEPROM_writeByte(EEPROM_STORE_ADDREESS+i, password[i]);
		g_Pass[i]=password[i];
		_delay_ms(50);
	}
}

uint8 Compare_passwords (uint8 *password1, uint8 *password2)
{
	uint8 i,u8Press_Num=0;
	for (i=0;i<PASSWORD_LENGTH;i++)
	{
		if (password1[i]==password2[i])
			u8Press_Num++;
	}
	if (u8Press_Num==PASSWORD_LENGTH)

		return PASSWORD_MATCH;
	else
		return PASSWORD_UNMATCH;
}

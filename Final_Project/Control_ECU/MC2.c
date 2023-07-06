#include "uart.h"
#include "CTRL.h"
#include "twi.h"
#include "DC_Motor.h"
#include <avr/io.h>

int main()
{
	uint8 RecieveGlobalPass[PASSWORD_LENGTH], RecievePass[PASSWORD_LENGTH];
	uint8 RecieveByte;

	UART_ConfigType UART_Config ={UART_8_BIT_DATA,UART_ONE_STOP_BIT,UART_NO_PARITY,9600};
	UART_init(&UART_Config);

	TWI_ConfigType TWI_Configuration = {0x02, 400};
	TWI_init(&TWI_Configuration);

	DcMotor_Init();
	Buzzer_init();

	while(1)
	{
		DcMotor_Rotate(DcMotor_u8FORWARD);

		while (UART_recieveByte() != M1_READY);
		UART_sendByte(M2_READY);

		Receive_password_from_HMI_ECU(RecieveGlobalPass);
		Save_passwordToEEPROM (g_Pass);

		while (UART_recieveByte() != M1_READY);
		UART_sendByte(MC2_READY);

		Receive_password_from_HMI_ECU(RecievePass);

		RecieveByte = Compare_passwords (g_Pass, RecievePass);

		if(RecieveByte == PASSWORD_MATCH)
		{
			DcMotor_Rotate(DcMotor_u8FORWARD);
		}
		else
		{
			DcMotor_Rotate(DcMotor_OFF);
		}
	}
}

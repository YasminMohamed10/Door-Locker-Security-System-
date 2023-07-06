#include "common_macros.h"
#include "gpio.h"
#include "DC_Motor.h"
#include "PWM.h"
#include <avr/io.h>


void DcMotor_Init(void)
{
	GPIO_setupPinDirection(DcMotor_PORT_ID , DcMotor_PIN1_ID , PIN_OUTPUT);
	GPIO_setupPinDirection(DcMotor_PORT_ID , DcMotor_PIN2_ID , PIN_OUTPUT);

	/*Stop DC Motor*/
	GPIO_writePin(DcMotor_PORT_ID , DcMotor_PIN1_ID , LOGIC_LOW);
	GPIO_writePin(DcMotor_PORT_ID , DcMotor_PIN2_ID , LOGIC_LOW);
}
void DcMotor_Rotate(uint8 state)
{
	uint8 Duty_Cycle;
	if (state == DcMotor_OFF){
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
	}
	else if (state == DcMotor_u8FORWARD){
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
}
	else{
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
}

	Duty_Cycle = (uint8)(((uint32)100*255)/(100));
	PWM_Timer0_Start(Duty_Cycle);
}

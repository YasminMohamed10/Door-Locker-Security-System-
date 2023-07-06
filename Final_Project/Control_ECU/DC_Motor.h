#ifndef DC_Motor_H_
#define DC_Motor_H_

#include "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DcMotor_PORT_ID         PORTD_ID

#define DcMotor_PIN1_ID         PIN6_ID
#define DcMotor_PIN2_ID         PIN7_ID

#define DcMotor_OFF             0
#define DcMotor_u8FORWARD       1
#define DcMotor_u8BACKWARD      2

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void DcMotor_Init(void);
void DcMotor_Rotate(uint8 state);


#endif

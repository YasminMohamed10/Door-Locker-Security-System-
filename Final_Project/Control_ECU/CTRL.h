#ifndef CTRL_H_
#define CTRL_H_

#include "std_types.h"

/**********Preprocessor Macros**********/

#define     PASSWORD_LENGTH              5
#define     EEPROM_STORE_ADDREESS        0x01

#define     M2_READY                     0x01
#define     M1_READY                     0x02
#define     MC2_READY                    0x03

#define     PASSWORD_MATCH               1
#define     PASSWORD_UNMATCH             0

#define     ACTIVATE_MOTOR               7
#define     ACTIVATE_BUZZER              6

#define     READY                        1
#define     NOT_READY                    0


/**************Global Variables***************/

uint8 g_Pass[PASSWORD_LENGTH];

/*********Function Prototypes*********/

void Receive_password_from_HMI_ECU (uint8 * password);
void Save_passwordToEEPROM (uint8 *password);
uint8 Compare_passwords (uint8 *password1, uint8 *password2);

#endif


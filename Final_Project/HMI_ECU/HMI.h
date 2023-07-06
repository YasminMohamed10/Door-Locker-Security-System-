 /******************************************************************************
 *
 * Module: HMI
 *
 * File Name: HMI.h
 *
 * Description: Header file for the HMI driver
 *
 * Author: Yasmin Mohamed
 *
 *******************************************************************************/

#ifndef HMI_H_
#define HMI_H_

#include "std_types.h"

/**********Preprocessor Macros**********/

#define PASSWORD_LENGTH                    5

#define ERROR                              0
#define SUCCESS                            1

#define M2_READY                           0x01
#define M1_READY                           0x02
#define MC2_READY                          0x03

#define PASSWORD_MATCH                     1
#define PASSWORD_UNMATCH                   0

#define ENTER_KEY                         '='

#define ACTIVATE_MOTOR                     7

#define ACTIVATE_BUZZER                    6

/**************Global Variables***************/

uint8 g_Password1[PASSWORD_LENGTH], g_Password2[PASSWORD_LENGTH], g_Password3[PASSWORD_LENGTH];

/*********Function Prototypes*********/

void HMI_CreatePassword(uint8* EnteredPass);
void HMI_ConfirmPassword(uint8* ReEnteredPass);
void HMI_EnterPassword(uint8* Enteredpass);
uint8 HMI_CheckifPassMatch(uint8* EnteredPass,uint8* ReEnteredPass);
void HMI_MainOptions(void);
void HMI_SendPassToCTR_ECU(uint8* u8_Password);


#endif

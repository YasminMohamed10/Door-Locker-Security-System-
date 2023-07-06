################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Buzzer.c \
../CTRL.c \
../DC_Motor.c \
../MC2.c \
../PWM.c \
../TIM1.c \
../external_eeprom.c \
../gpio.c \
../twi.c \
../uart.c 

OBJS += \
./Buzzer.o \
./CTRL.o \
./DC_Motor.o \
./MC2.o \
./PWM.o \
./TIM1.o \
./external_eeprom.o \
./gpio.o \
./twi.o \
./uart.o 

C_DEPS += \
./Buzzer.d \
./CTRL.d \
./DC_Motor.d \
./MC2.d \
./PWM.d \
./TIM1.d \
./external_eeprom.d \
./gpio.d \
./twi.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



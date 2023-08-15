################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/keypad_driver/keypad.c 

OBJS += \
./HAL/keypad_driver/keypad.o 

C_DEPS += \
./HAL/keypad_driver/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/keypad_driver/keypad.o: ../HAL/keypad_driver/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Embedded/KEROLES/Mastering Embedded System/github/Mastering-Embedded-Diploma/DRIVERS/STM32F103C6_Drivers/MCAL/includes" -I"D:/Embedded/KEROLES/Mastering Embedded System/github/Mastering-Embedded-Diploma/DRIVERS/STM32F103C6_Drivers/HAL/inlcudes" -I"D:/Embedded/KEROLES/Mastering Embedded System/github/Mastering-Embedded-Diploma/DRIVERS/STM32F103C6_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/keypad_driver/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


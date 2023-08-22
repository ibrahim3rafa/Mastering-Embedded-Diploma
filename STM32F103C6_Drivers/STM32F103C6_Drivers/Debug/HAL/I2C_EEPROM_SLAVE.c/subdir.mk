################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/I2C_EEPROM_SLAVE.c/I2C_EEPROM_SLAVE.c 

OBJS += \
./HAL/I2C_EEPROM_SLAVE.c/I2C_EEPROM_SLAVE.o 

C_DEPS += \
./HAL/I2C_EEPROM_SLAVE.c/I2C_EEPROM_SLAVE.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/I2C_EEPROM_SLAVE.c/I2C_EEPROM_SLAVE.o: ../HAL/I2C_EEPROM_SLAVE.c/I2C_EEPROM_SLAVE.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Embedded/KEROLES/Mastering Embedded System/github/Mastering-Embedded-Diploma/STM32F103C6_Drivers/STM32F103C6_Drivers/MCAL/includes" -I"D:/Embedded/KEROLES/Mastering Embedded System/github/Mastering-Embedded-Diploma/STM32F103C6_Drivers/STM32F103C6_Drivers/HAL/inlcudes" -I"D:/Embedded/KEROLES/Mastering Embedded System/github/Mastering-Embedded-Diploma/STM32F103C6_Drivers/STM32F103C6_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/I2C_EEPROM_SLAVE.c/I2C_EEPROM_SLAVE.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


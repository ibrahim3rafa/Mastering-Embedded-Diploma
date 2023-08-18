################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/SPI_driver/SPI.c 

OBJS += \
./MCAL/SPI_driver/SPI.o 

C_DEPS += \
./MCAL/SPI_driver/SPI.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/SPI_driver/SPI.o: ../MCAL/SPI_driver/SPI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Embedded/KEROLES/Mastering Embedded System/github/Mastering-Embedded-Diploma/STM32F103C6_Drivers/STM32F103C6_Drivers/MCAL/includes" -I"D:/Embedded/KEROLES/Mastering Embedded System/github/Mastering-Embedded-Diploma/STM32F103C6_Drivers/STM32F103C6_Drivers/HAL/inlcudes" -I"D:/Embedded/KEROLES/Mastering Embedded System/github/Mastering-Embedded-Diploma/STM32F103C6_Drivers/STM32F103C6_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/SPI_driver/SPI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


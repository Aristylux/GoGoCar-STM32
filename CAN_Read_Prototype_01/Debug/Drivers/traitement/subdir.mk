################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/traitement/traitement_data.c 

OBJS += \
./Drivers/traitement/traitement_data.o 

C_DEPS += \
./Drivers/traitement/traitement_data.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/traitement/%.o Drivers/traitement/%.su: ../Drivers/traitement/%.c Drivers/traitement/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/Documents/STM32/GoGoCar-STM32-main/CAN_Read_Prototype_01/Drivers/conversion_can" -I"D:/Documents/STM32/GoGoCar-STM32-main/CAN_Read_Prototype_01/Drivers/traitement" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-traitement

clean-Drivers-2f-traitement:
	-$(RM) ./Drivers/traitement/traitement_data.d ./Drivers/traitement/traitement_data.o ./Drivers/traitement/traitement_data.su

.PHONY: clean-Drivers-2f-traitement


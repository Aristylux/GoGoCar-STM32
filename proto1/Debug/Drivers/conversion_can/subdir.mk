################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/conversion_can/conversion_can.c 

OBJS += \
./Drivers/conversion_can/conversion_can.o 

C_DEPS += \
./Drivers/conversion_can/conversion_can.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/conversion_can/%.o Drivers/conversion_can/%.su: ../Drivers/conversion_can/%.c Drivers/conversion_can/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/samud/STM32CubeIDE/workspace_1.9.0/proto1/Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-conversion_can

clean-Drivers-2f-conversion_can:
	-$(RM) ./Drivers/conversion_can/conversion_can.d ./Drivers/conversion_can/conversion_can.o ./Drivers/conversion_can/conversion_can.su

.PHONY: clean-Drivers-2f-conversion_can


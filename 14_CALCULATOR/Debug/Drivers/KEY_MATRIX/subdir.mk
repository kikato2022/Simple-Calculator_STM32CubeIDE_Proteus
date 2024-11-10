################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/KEY_MATRIX/key_matrix.c 

OBJS += \
./Drivers/KEY_MATRIX/key_matrix.o 

C_DEPS += \
./Drivers/KEY_MATRIX/key_matrix.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/KEY_MATRIX/%.o Drivers/KEY_MATRIX/%.su Drivers/KEY_MATRIX/%.cyclo: ../Drivers/KEY_MATRIX/%.c Drivers/KEY_MATRIX/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/LCD1602 -I../Drivers/KEY_MATRIX -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-KEY_MATRIX

clean-Drivers-2f-KEY_MATRIX:
	-$(RM) ./Drivers/KEY_MATRIX/key_matrix.cyclo ./Drivers/KEY_MATRIX/key_matrix.d ./Drivers/KEY_MATRIX/key_matrix.o ./Drivers/KEY_MATRIX/key_matrix.su

.PHONY: clean-Drivers-2f-KEY_MATRIX


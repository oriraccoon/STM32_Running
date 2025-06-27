################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/driver/FND/FND.c 

OBJS += \
./Core/driver/FND/FND.o 

C_DEPS += \
./Core/driver/FND/FND.d 


# Each subdirectory must supply rules for building sources it contributes
Core/driver/FND/%.o Core/driver/FND/%.su Core/driver/FND/%.cyclo: ../Core/driver/FND/%.c Core/driver/FND/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/kccistc/Documents/GitHub/STM32_Running/0626_zero_mini_project/Core/ap" -I"C:/Users/kccistc/Documents/GitHub/STM32_Running/0626_zero_mini_project/Core/driver/Button" -I"C:/Users/kccistc/Documents/GitHub/STM32_Running/0626_zero_mini_project/Core/driver/FND" -I"C:/Users/kccistc/Documents/GitHub/STM32_Running/0626_zero_mini_project/Core/driver/LedBar" -I"C:/Users/kccistc/Documents/GitHub/STM32_Running/0626_zero_mini_project/Core/ap/Inc" -I"C:/Users/kccistc/Documents/GitHub/STM32_Running/0626_zero_mini_project/Core/ap/src" -I"C:/Users/kccistc/Documents/GitHub/STM32_Running/0626_zero_mini_project/Core/driver/LCD" -I"C:/Users/kccistc/Documents/GitHub/STM32_Running/0626_zero_mini_project/Core/driver/buzzer" -I"C:/Users/kccistc/Documents/GitHub/STM32_Running/0626_zero_mini_project/Core/driver/DC_Motor" -I"C:/Users/kccistc/Documents/GitHub/STM32_Running/0626_zero_mini_project/Core/driver/Ultra" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-driver-2f-FND

clean-Core-2f-driver-2f-FND:
	-$(RM) ./Core/driver/FND/FND.cyclo ./Core/driver/FND/FND.d ./Core/driver/FND/FND.o ./Core/driver/FND/FND.su

.PHONY: clean-Core-2f-driver-2f-FND


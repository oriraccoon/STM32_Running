################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f411retx.s 

OBJS += \
./Core/Startup/startup_stm32f411retx.o 

S_DEPS += \
./Core/Startup/startup_stm32f411retx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/ap" -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/driver/Button" -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/driver/FND" -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/driver/LedBar" -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/ap/Inc" -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/ap/src" -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/Src" -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/driver/LCD" -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/driver/buzzer" -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/driver/DC_Motor" -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/driver/Ultra" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f411retx.d ./Core/Startup/startup_stm32f411retx.o

.PHONY: clean-Core-2f-Startup


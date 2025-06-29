################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ap/src/Controller.c \
../Core/ap/src/Listener.c \
../Core/ap/src/Motor_Speed.c \
../Core/ap/src/Octave.c \
../Core/ap/src/Presenter.c \
../Core/ap/src/Sound.c \
../Core/ap/src/ap_main.c \
../Core/ap/src/queue.c \
../Core/ap/src/stopWatch.c \
../Core/ap/src/timeWatch.c 

OBJS += \
./Core/ap/src/Controller.o \
./Core/ap/src/Listener.o \
./Core/ap/src/Motor_Speed.o \
./Core/ap/src/Octave.o \
./Core/ap/src/Presenter.o \
./Core/ap/src/Sound.o \
./Core/ap/src/ap_main.o \
./Core/ap/src/queue.o \
./Core/ap/src/stopWatch.o \
./Core/ap/src/timeWatch.o 

C_DEPS += \
./Core/ap/src/Controller.d \
./Core/ap/src/Listener.d \
./Core/ap/src/Motor_Speed.d \
./Core/ap/src/Octave.d \
./Core/ap/src/Presenter.d \
./Core/ap/src/Sound.d \
./Core/ap/src/ap_main.d \
./Core/ap/src/queue.d \
./Core/ap/src/stopWatch.d \
./Core/ap/src/timeWatch.d 


# Each subdirectory must supply rules for building sources it contributes
Core/ap/src/%.o Core/ap/src/%.su Core/ap/src/%.cyclo: ../Core/ap/src/%.c Core/ap/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/ap" -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/driver/Button" -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/driver/FND" -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/driver/LedBar" -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/ap/Inc" -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/ap/src" -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/driver/LCD" -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/driver/buzzer" -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/driver/DC_Motor" -I"C:/Users/kccistc/Desktop/asd/0626_zero_mini_project/Core/driver/Ultra" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-ap-2f-src

clean-Core-2f-ap-2f-src:
	-$(RM) ./Core/ap/src/Controller.cyclo ./Core/ap/src/Controller.d ./Core/ap/src/Controller.o ./Core/ap/src/Controller.su ./Core/ap/src/Listener.cyclo ./Core/ap/src/Listener.d ./Core/ap/src/Listener.o ./Core/ap/src/Listener.su ./Core/ap/src/Motor_Speed.cyclo ./Core/ap/src/Motor_Speed.d ./Core/ap/src/Motor_Speed.o ./Core/ap/src/Motor_Speed.su ./Core/ap/src/Octave.cyclo ./Core/ap/src/Octave.d ./Core/ap/src/Octave.o ./Core/ap/src/Octave.su ./Core/ap/src/Presenter.cyclo ./Core/ap/src/Presenter.d ./Core/ap/src/Presenter.o ./Core/ap/src/Presenter.su ./Core/ap/src/Sound.cyclo ./Core/ap/src/Sound.d ./Core/ap/src/Sound.o ./Core/ap/src/Sound.su ./Core/ap/src/ap_main.cyclo ./Core/ap/src/ap_main.d ./Core/ap/src/ap_main.o ./Core/ap/src/ap_main.su ./Core/ap/src/queue.cyclo ./Core/ap/src/queue.d ./Core/ap/src/queue.o ./Core/ap/src/queue.su ./Core/ap/src/stopWatch.cyclo ./Core/ap/src/stopWatch.d ./Core/ap/src/stopWatch.o ./Core/ap/src/stopWatch.su ./Core/ap/src/timeWatch.cyclo ./Core/ap/src/timeWatch.d ./Core/ap/src/timeWatch.o ./Core/ap/src/timeWatch.su

.PHONY: clean-Core-2f-ap-2f-src


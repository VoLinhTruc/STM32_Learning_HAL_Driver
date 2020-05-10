################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Bico/Desktop/STM32_Learning_HAL_Driver/My_Lib/Snake_Queue/Snake_Queue.c 

OBJS += \
./Snake_Queue/Snake_Queue.o 

C_DEPS += \
./Snake_Queue/Snake_Queue.d 


# Each subdirectory must supply rules for building sources it contributes
Snake_Queue/Snake_Queue.o: C:/Users/Bico/Desktop/STM32_Learning_HAL_Driver/My_Lib/Snake_Queue/Snake_Queue.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/Bico/Desktop/STM32_Learning_HAL_Driver/My_Lib/Snake_Queue" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Snake_Queue/Snake_Queue.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


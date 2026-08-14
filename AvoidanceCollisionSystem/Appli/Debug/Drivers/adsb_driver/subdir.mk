################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/adsb_driver/adsb_driver.c 

OBJS += \
./Drivers/adsb_driver/adsb_driver.o 

C_DEPS += \
./Drivers/adsb_driver/adsb_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/adsb_driver/%.o Drivers/adsb_driver/%.su Drivers/adsb_driver/%.cyclo: ../Drivers/adsb_driver/%.c Drivers/adsb_driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m55 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32N657xx -c -I../Core/Inc -I../../Secure_nsclib -I../../Drivers/STM32N6xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32N6xx/Include -I../../Drivers/STM32N6xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Include -I"C:/Users/gdnoriega/Documents/ACAS_Xu_WorkSpace/AvoidanceCollisionSystem/Appli/Drivers/adsb_driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -mcmse -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-adsb_driver

clean-Drivers-2f-adsb_driver:
	-$(RM) ./Drivers/adsb_driver/adsb_driver.cyclo ./Drivers/adsb_driver/adsb_driver.d ./Drivers/adsb_driver/adsb_driver.o ./Drivers/adsb_driver/adsb_driver.su

.PHONY: clean-Drivers-2f-adsb_driver


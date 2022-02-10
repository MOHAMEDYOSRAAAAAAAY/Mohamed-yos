################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/AT85_DIO/AT85_DIO_Program.c 

OBJS += \
./MCAL/AT85_DIO/AT85_DIO_Program.o 

C_DEPS += \
./MCAL/AT85_DIO/AT85_DIO_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/AT85_DIO/%.o: ../MCAL/AT85_DIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=attiny85 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



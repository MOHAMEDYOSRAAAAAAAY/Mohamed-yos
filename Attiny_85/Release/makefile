################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/AT85_DIO/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Attiny_85.lss \

FLASH_IMAGE += \
Attiny_85.hex \

EEPROM_IMAGE += \
Attiny_85.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Attiny_85.elf secondary-outputs

# Tool invocations
Attiny_85.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Attiny_85.map -mmcu=attiny85 -o "Attiny_85.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Attiny_85.lss: Attiny_85.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Attiny_85.elf  >"Attiny_85.lss"
	@echo 'Finished building: $@'
	@echo ' '

Attiny_85.hex: Attiny_85.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Attiny_85.elf  "Attiny_85.hex"
	@echo 'Finished building: $@'
	@echo ' '

Attiny_85.eep: Attiny_85.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Attiny_85.elf  "Attiny_85.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Attiny_85.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=attiny85 Attiny_85.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Attiny_85.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

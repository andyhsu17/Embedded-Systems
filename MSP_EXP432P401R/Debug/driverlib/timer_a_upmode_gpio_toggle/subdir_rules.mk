################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
driverlib/timer_a_upmode_gpio_toggle/system_msp432p401r.obj: ../driverlib/timer_a_upmode_gpio_toggle/system_msp432p401r.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv7/ccs_base/arm/include" --include_path="/Applications/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="/Users/andyhsu/Downloads/MSP_EXP432P401R" --include_path="/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="driverlib/timer_a_upmode_gpio_toggle/system_msp432p401r.d" --obj_directory="driverlib/timer_a_upmode_gpio_toggle" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driverlib/timer_a_upmode_gpio_toggle/timer_a_upmode_gpio_toggle.obj: ../driverlib/timer_a_upmode_gpio_toggle/timer_a_upmode_gpio_toggle.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv7/ccs_base/arm/include" --include_path="/Applications/ti/ccsv7/ccs_base/arm/include/CMSIS" --include_path="/Users/andyhsu/Downloads/MSP_EXP432P401R" --include_path="/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="driverlib/timer_a_upmode_gpio_toggle/timer_a_upmode_gpio_toggle.d" --obj_directory="driverlib/timer_a_upmode_gpio_toggle" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '



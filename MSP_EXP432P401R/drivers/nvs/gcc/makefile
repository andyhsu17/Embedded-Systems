SIMPLELINK_MSP432_SDK_INSTALL_DIR ?= $(abspath ../../../../../..)

include $(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/imports.mak

CC = "$(GCC_ARMCOMPILER)/bin/arm-none-eabi-gcc"
LNK = "$(GCC_ARMCOMPILER)/bin/arm-none-eabi-gcc"

OBJECTS = main_nortos.obj nvs.obj MSP_EXP432P401R.obj

NAME = nvs

CFLAGS = -I.. "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source" "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/third_party/CMSIS/Include" -DDeviceFamily_MSP432P401x "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/kernel/nortos" "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/kernel/nortos/posix" -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -ffunction-sections -fdata-sections -g -gstrict-dwarf -Wall "-I$(GCC_ARMCOMPILER)/arm-none-eabi/include/newlib-nano" "-I$(GCC_ARMCOMPILER)/arm-none-eabi/include"

LFLAGS = -Wl,-T,../gcc/MSP_EXP432P401R_NoRTOS.lds "-Wl,-Map,$(NAME).map" -nostartfiles "-L$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/display/lib" -l:display.am4fg "-L$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/drivers/lib" -l:drivers_msp432p401x.am4fg "-L$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/third_party/fatfs/lib" -l:fatfs.am4fg -eresetISR "-L$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/kernel/nortos/lib" -l:nortos_msp432p401x.am4fg "-L$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/devices/msp432p4xx/driverlib/gcc" -l:msp432p4xx_driverlib.a -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -static -Wl,--gc-sections "-L$(GCC_ARMCOMPILER)/arm-none-eabi/lib/thumb/v7e-m/fpv4-sp/hard" -lgcc -lc -lm -lnosys --specs=nano.specs

all: $(NAME).out

main_nortos.obj: ../main_nortos.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

nvs.obj: ../nvs.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

MSP_EXP432P401R.obj: ../MSP_EXP432P401R.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

$(NAME).out: $(OBJECTS)
	@ echo linking...
	@ $(LNK)  $(OBJECTS) $(LFLAGS) -o $(NAME).out

clean:
	@ echo Cleaning...
	@ $(RM) $(OBJECTS) > $(DEVNULL) 2>&1
	@ $(RM) $(NAME).out > $(DEVNULL) 2>&1
	@ $(RM) $(NAME).map > $(DEVNULL) 2>&1

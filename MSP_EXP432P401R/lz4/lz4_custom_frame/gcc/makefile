SIMPLELINK_MSP432_SDK_INSTALL_DIR ?= $(abspath ../../../../../..)

include $(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/imports.mak

CC = "$(GCC_ARMCOMPILER)/bin/arm-none-eabi-gcc"
LNK = "$(GCC_ARMCOMPILER)/bin/arm-none-eabi-gcc"

OBJECTS = system_msp432p401r.obj startup_msp432p401r_gcc.obj main.obj

NAME = lz4_custom_frame

CFLAGS = -I.. "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/third_party/CMSIS/Include" "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source" -D__MSP432P401R__ -DDeviceFamily_MSP432P401x -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -ffunction-sections -fdata-sections -g -gstrict-dwarf -Wall "-I$(GCC_ARMCOMPILER)/arm-none-eabi/include/newlib-nano" "-I$(GCC_ARMCOMPILER)/arm-none-eabi/include"

LFLAGS = "-L$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/compression/lz4/lib/gcc/m4f" -l:lz4.a -Wl,-T,../gcc/msp432p401r.lds "-Wl,-Map,$(NAME).map" "-L$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/display/lib" -l:display.am4fg "-L$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/drivers/lib" -l:drivers_msp432p401x.am4fg "-L$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/third_party/fatfs/lib" -l:fatfs.am4fg "-L$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/devices/msp432p4xx/driverlib/gcc" -l:msp432p4xx_driverlib.a -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -static -Wl,--gc-sections "-L$(GCC_ARMCOMPILER)/arm-none-eabi/lib/thumb/v7e-m/fpv4-sp/hard" -lgcc -lc -lm -lnosys --specs=nano.specs

all: $(NAME).out

system_msp432p401r.obj: ../system_msp432p401r.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

startup_msp432p401r_gcc.obj: ../gcc/startup_msp432p401r_gcc.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

main.obj: ../main.c
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

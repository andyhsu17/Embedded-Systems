SIMPLELINK_MSP432_SDK_INSTALL_DIR ?= $(abspath ../../../../../..)

include $(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/imports.mak

CC = "$(CCS_ARMCOMPILER)/bin/armcl"
LNK = "$(CCS_ARMCOMPILER)/bin/armcl"

OBJECTS = main_nortos.obj watchdog.obj MSP_EXP432P401R.obj

NAME = watchdog

CFLAGS = -I.. "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source" "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/third_party/CMSIS/Include" -DDeviceFamily_MSP432P401x --advice:power=none "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/kernel/nortos" "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/kernel/nortos/posix" --silicon_version=7M4 --code_state=16 --little_endian --display_error_number --diag_warning=255 --diag_wrap=off --gen_func_subsections=on --float_support=FPv4SPD16 --symdebug:dwarf "-I$(CCS_ARMCOMPILER)/include"

LFLAGS = "-l$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/display/lib/display.aem4f" "-l$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/drivers/lib/drivers_msp432p401x.aem4f" "-l$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/third_party/fatfs/lib/fatfs.aem4f" --diag_suppress=10063 --entry_point=resetISR "-l$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/kernel/nortos/lib/nortos_msp432p401x.aem4f" "-l$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/devices/msp432p4xx/driverlib/ccs/msp432p4xx_driverlib.lib" ../ccs/MSP_EXP432P401R_NoRTOS.cmd "-m$(NAME).map" --warn_sections --display_error_number --diag_wrap=off --rom_model "-i$(CCS_ARMCOMPILER)/lib" -llibc.a

all: $(NAME).out

main_nortos.obj: ../main_nortos.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

watchdog.obj: ../watchdog.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

MSP_EXP432P401R.obj: ../MSP_EXP432P401R.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

$(NAME).out: $(OBJECTS)
	@ echo linking...
	@ $(LNK) $(CFLAGS) -z $(OBJECTS) $(LFLAGS) -o $(NAME).out

clean:
	@ echo Cleaning...
	@ $(RM) $(OBJECTS) > $(DEVNULL) 2>&1
	@ $(RM) $(NAME).out > $(DEVNULL) 2>&1
	@ $(RM) $(NAME).map > $(DEVNULL) 2>&1

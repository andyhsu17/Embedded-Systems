SIMPLELINK_MSP432_SDK_INSTALL_DIR ?= $(abspath ../../../../../..)

include $(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/imports.mak

CC = "$(CCS_ARMCOMPILER)/bin/armcl"
LNK = "$(CCS_ARMCOMPILER)/bin/armcl"

OBJECTS = system_msp432p401r.obj startup_msp432p401r_ccs.obj msp432p401x_ta0_02.obj

NAME = msp432p401x_ta0_02

CFLAGS = -I.. "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source" "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/third_party/CMSIS/Include" -D__MSP432P401R__ -DDeviceFamily_MSP432P401x --advice:power=none --silicon_version=7M4 --code_state=16 --little_endian --display_error_number --diag_warning=255 --diag_wrap=off --gen_func_subsections=on --float_support=FPv4SPD16 --symdebug:dwarf "-I$(CCS_ARMCOMPILER)/include"

LFLAGS = "-l$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/display/lib/display.aem4f" "-l$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/drivers/lib/drivers_msp432p401x.aem4f" "-l$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/third_party/fatfs/lib/fatfs.aem4f" --stack_size=512 "-l$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/devices/msp432p4xx/driverlib/ccs/msp432p4xx_driverlib.lib" ../ccs/msp432p401r.cmd "-m$(NAME).map" --warn_sections --display_error_number --diag_wrap=off --rom_model "-i$(CCS_ARMCOMPILER)/lib" -llibc.a

all: $(NAME).out

system_msp432p401r.obj: ../system_msp432p401r.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

startup_msp432p401r_ccs.obj: ../ccs/startup_msp432p401r_ccs.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

msp432p401x_ta0_02.obj: ../msp432p401x_ta0_02.c
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

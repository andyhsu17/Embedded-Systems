SIMPLELINK_MSP432_SDK_INSTALL_DIR ?= $(abspath ../../../../../..)

include $(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/imports.mak

CC = "$(IAR_ARMCOMPILER)/bin/iccarm"
LNK = "$(IAR_ARMCOMPILER)/bin/ilinkarm"

OBJECTS = main_nortos.obj nvsuart.obj MSP_EXP432P401R.obj

NAME = nvsuart

CFLAGS = -I.. "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source" "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/third_party/CMSIS/Include" -DDeviceFamily_MSP432P401x "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/kernel/nortos" "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/kernel/nortos/posix" --cpu=Cortex-M4F --debug --silent -e --aeabi --thumb --diag_suppress=Pa050 "-I$(IAR_ARMCOMPILER)/inc/c"

LFLAGS = "$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/display/lib/display.arm4f" "$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/drivers/lib/drivers_msp432p401x.arm4f" "$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/third_party/fatfs/lib/fatfs.arm4f" "$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/kernel/nortos/lib/nortos_msp432p401x.arm4f" "$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/devices/msp432p4xx/driverlib/iar/msp432p4xx_driverlib.a" --config ../iar/MSP_EXP432P401R_NoRTOS.icf --map "$(NAME).map" --silent --cpu=Cortex-M4F --redirect _Printf=_PrintfSmall --redirect _Scanf=_ScanfSmall --semihosting=iar_breakpoint

all: $(NAME).out

main_nortos.obj: ../main_nortos.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -o $@

nvsuart.obj: ../nvsuart.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -o $@

MSP_EXP432P401R.obj: ../MSP_EXP432P401R.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -o $@

$(NAME).out: $(OBJECTS)
	@ echo linking...
	@ $(LNK)  $(OBJECTS) $(LFLAGS) -o $(NAME).out

clean:
	@ echo Cleaning...
	@ $(RM) $(OBJECTS) > $(DEVNULL) 2>&1
	@ $(RM) $(NAME).out > $(DEVNULL) 2>&1
	@ $(RM) $(NAME).map > $(DEVNULL) 2>&1

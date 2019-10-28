SIMPLELINK_MSP432_SDK_INSTALL_DIR ?= $(abspath ../../../../../..)

include $(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/imports.mak

CC = "$(CCS_ARMCOMPILER)/bin/armcl"
LNK = "$(CCS_ARMCOMPILER)/bin/armcl"

OBJECTS = system_msp432p401r.obj LPRocket_96x37.obj TI_Logo_69x64.obj Sharp96x96.obj Sharp96x96utils.obj fontcm12.obj fontcm12b.obj fontcm12i.obj fontcm14.obj fontcm14b.obj fontcm14i.obj fontcm16.obj fontcm16b.obj fontcm16i.obj fontcm18.obj fontcm18b.obj fontcm18i.obj fontcm20.obj fontcm20b.obj fontcm20i.obj fontcm22.obj fontcm22b.obj fontcm22i.obj fontcm24.obj fontcm24b.obj fontcm24i.obj fontcm26.obj fontcm26b.obj fontcm26i.obj fontcm28.obj fontcm28b.obj fontcm28i.obj fontcm30.obj fontcm30b.obj fontcm30i.obj fontcm32.obj fontcm32b.obj fontcm32i.obj fontcm34.obj fontcm34b.obj fontcm34i.obj fontcm36.obj fontcm36b.obj fontcm36i.obj fontcm38.obj fontcm38b.obj fontcm38i.obj fontcm40.obj fontcm40b.obj fontcm40i.obj fontcm42.obj fontcm42b.obj fontcm42i.obj fontcm44.obj fontcm44b.obj fontcm44i.obj fontcm46.obj fontcm46b.obj fontcm46i.obj fontcm48.obj fontcm48b.obj fontcm48i.obj fontcmsc12.obj fontcmsc14.obj fontcmsc16.obj fontcmsc18.obj fontcmsc20.obj fontcmsc22.obj fontcmsc24.obj fontcmsc26.obj fontcmsc28.obj fontcmsc30.obj fontcmsc32.obj fontcmsc34.obj fontcmsc36.obj fontcmsc38.obj fontcmsc40.obj fontcmsc42.obj fontcmsc44.obj fontcmsc46.obj fontcmsc48.obj fontcmss12.obj fontcmss12b.obj fontcmss12i.obj fontcmss14.obj fontcmss14b.obj fontcmss14i.obj fontcmss16.obj fontcmss16b.obj fontcmss16i.obj fontcmss18.obj fontcmss18b.obj fontcmss18i.obj fontcmss20.obj fontcmss20b.obj fontcmss20i.obj fontcmss22.obj fontcmss22b.obj fontcmss22i.obj fontcmss24.obj fontcmss24b.obj fontcmss24i.obj fontcmss26.obj fontcmss26b.obj fontcmss26i.obj fontcmss28.obj fontcmss28b.obj fontcmss28i.obj fontcmss30.obj fontcmss30b.obj fontcmss30i.obj fontcmss32.obj fontcmss32b.obj fontcmss32i.obj fontcmss34.obj fontcmss34b.obj fontcmss34i.obj fontcmss36.obj fontcmss36b.obj fontcmss36i.obj fontcmss38.obj fontcmss38b.obj fontcmss38i.obj fontcmss40.obj fontcmss40b.obj fontcmss40i.obj fontcmss42.obj fontcmss42b.obj fontcmss42i.obj fontcmss44.obj fontcmss44b.obj fontcmss44i.obj fontcmss46.obj fontcmss46b.obj fontcmss46i.obj fontcmss48.obj fontcmss48b.obj fontcmss48i.obj fontcmtt12.obj fontcmtt14.obj fontcmtt16.obj fontcmtt18.obj fontcmtt20.obj fontcmtt22.obj fontcmtt24.obj fontcmtt26.obj fontcmtt28.obj fontcmtt30.obj fontcmtt32.obj fontcmtt34.obj fontcmtt36.obj fontcmtt38.obj fontcmtt40.obj fontcmtt42.obj fontcmtt44.obj fontcmtt46.obj fontcmtt48.obj fontfixed6x8.obj startup_msp432p401r_ccs.obj main.obj

NAME = 430boost_sharp96_grlibexample_msp432p401r

CFLAGS = -I.. "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source" "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/third_party/CMSIS/Include" -D__MSP432P401R__ -DDeviceFamily_MSP432P401x --advice:power=none --silicon_version=7M4 --code_state=16 --little_endian --display_error_number --diag_warning=255 --diag_wrap=off --gen_func_subsections=on --float_support=FPv4SPD16 --symdebug:dwarf "-I$(CCS_ARMCOMPILER)/include"

LFLAGS = "-l$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/grlib/ccs/grlib.lib" "-l$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/display/lib/display.aem4f" "-l$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/drivers/lib/drivers_msp432p401x.aem4f" "-l$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/third_party/fatfs/lib/fatfs.aem4f" --stack_size=512 "-l$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/devices/msp432p4xx/driverlib/ccs/msp432p4xx_driverlib.lib" ../ccs/msp432p401r.cmd "-m$(NAME).map" --warn_sections --display_error_number --diag_wrap=off --rom_model "-i$(CCS_ARMCOMPILER)/lib" -llibc.a

all: $(NAME).out

system_msp432p401r.obj: ../system_msp432p401r.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

LPRocket_96x37.obj: ../images/LPRocket_96x37.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

TI_Logo_69x64.obj: ../images/TI_Logo_69x64.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

Sharp96x96.obj: ../LcdDriver/Sharp96x96.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

Sharp96x96utils.obj: ../LcdDriver/Sharp96x96utils.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm12.obj: ../fonts/fontcm12.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm12b.obj: ../fonts/fontcm12b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm12i.obj: ../fonts/fontcm12i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm14.obj: ../fonts/fontcm14.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm14b.obj: ../fonts/fontcm14b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm14i.obj: ../fonts/fontcm14i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm16.obj: ../fonts/fontcm16.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm16b.obj: ../fonts/fontcm16b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm16i.obj: ../fonts/fontcm16i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm18.obj: ../fonts/fontcm18.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm18b.obj: ../fonts/fontcm18b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm18i.obj: ../fonts/fontcm18i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm20.obj: ../fonts/fontcm20.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm20b.obj: ../fonts/fontcm20b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm20i.obj: ../fonts/fontcm20i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm22.obj: ../fonts/fontcm22.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm22b.obj: ../fonts/fontcm22b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm22i.obj: ../fonts/fontcm22i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm24.obj: ../fonts/fontcm24.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm24b.obj: ../fonts/fontcm24b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm24i.obj: ../fonts/fontcm24i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm26.obj: ../fonts/fontcm26.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm26b.obj: ../fonts/fontcm26b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm26i.obj: ../fonts/fontcm26i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm28.obj: ../fonts/fontcm28.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm28b.obj: ../fonts/fontcm28b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm28i.obj: ../fonts/fontcm28i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm30.obj: ../fonts/fontcm30.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm30b.obj: ../fonts/fontcm30b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm30i.obj: ../fonts/fontcm30i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm32.obj: ../fonts/fontcm32.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm32b.obj: ../fonts/fontcm32b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm32i.obj: ../fonts/fontcm32i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm34.obj: ../fonts/fontcm34.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm34b.obj: ../fonts/fontcm34b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm34i.obj: ../fonts/fontcm34i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm36.obj: ../fonts/fontcm36.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm36b.obj: ../fonts/fontcm36b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm36i.obj: ../fonts/fontcm36i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm38.obj: ../fonts/fontcm38.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm38b.obj: ../fonts/fontcm38b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm38i.obj: ../fonts/fontcm38i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm40.obj: ../fonts/fontcm40.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm40b.obj: ../fonts/fontcm40b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm40i.obj: ../fonts/fontcm40i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm42.obj: ../fonts/fontcm42.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm42b.obj: ../fonts/fontcm42b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm42i.obj: ../fonts/fontcm42i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm44.obj: ../fonts/fontcm44.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm44b.obj: ../fonts/fontcm44b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm44i.obj: ../fonts/fontcm44i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm46.obj: ../fonts/fontcm46.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm46b.obj: ../fonts/fontcm46b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm46i.obj: ../fonts/fontcm46i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm48.obj: ../fonts/fontcm48.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm48b.obj: ../fonts/fontcm48b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcm48i.obj: ../fonts/fontcm48i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmsc12.obj: ../fonts/fontcmsc12.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmsc14.obj: ../fonts/fontcmsc14.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmsc16.obj: ../fonts/fontcmsc16.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmsc18.obj: ../fonts/fontcmsc18.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmsc20.obj: ../fonts/fontcmsc20.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmsc22.obj: ../fonts/fontcmsc22.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmsc24.obj: ../fonts/fontcmsc24.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmsc26.obj: ../fonts/fontcmsc26.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmsc28.obj: ../fonts/fontcmsc28.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmsc30.obj: ../fonts/fontcmsc30.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmsc32.obj: ../fonts/fontcmsc32.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmsc34.obj: ../fonts/fontcmsc34.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmsc36.obj: ../fonts/fontcmsc36.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmsc38.obj: ../fonts/fontcmsc38.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmsc40.obj: ../fonts/fontcmsc40.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmsc42.obj: ../fonts/fontcmsc42.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmsc44.obj: ../fonts/fontcmsc44.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmsc46.obj: ../fonts/fontcmsc46.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmsc48.obj: ../fonts/fontcmsc48.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss12.obj: ../fonts/fontcmss12.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss12b.obj: ../fonts/fontcmss12b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss12i.obj: ../fonts/fontcmss12i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss14.obj: ../fonts/fontcmss14.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss14b.obj: ../fonts/fontcmss14b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss14i.obj: ../fonts/fontcmss14i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss16.obj: ../fonts/fontcmss16.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss16b.obj: ../fonts/fontcmss16b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss16i.obj: ../fonts/fontcmss16i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss18.obj: ../fonts/fontcmss18.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss18b.obj: ../fonts/fontcmss18b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss18i.obj: ../fonts/fontcmss18i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss20.obj: ../fonts/fontcmss20.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss20b.obj: ../fonts/fontcmss20b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss20i.obj: ../fonts/fontcmss20i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss22.obj: ../fonts/fontcmss22.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss22b.obj: ../fonts/fontcmss22b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss22i.obj: ../fonts/fontcmss22i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss24.obj: ../fonts/fontcmss24.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss24b.obj: ../fonts/fontcmss24b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss24i.obj: ../fonts/fontcmss24i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss26.obj: ../fonts/fontcmss26.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss26b.obj: ../fonts/fontcmss26b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss26i.obj: ../fonts/fontcmss26i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss28.obj: ../fonts/fontcmss28.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss28b.obj: ../fonts/fontcmss28b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss28i.obj: ../fonts/fontcmss28i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss30.obj: ../fonts/fontcmss30.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss30b.obj: ../fonts/fontcmss30b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss30i.obj: ../fonts/fontcmss30i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss32.obj: ../fonts/fontcmss32.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss32b.obj: ../fonts/fontcmss32b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss32i.obj: ../fonts/fontcmss32i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss34.obj: ../fonts/fontcmss34.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss34b.obj: ../fonts/fontcmss34b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss34i.obj: ../fonts/fontcmss34i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss36.obj: ../fonts/fontcmss36.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss36b.obj: ../fonts/fontcmss36b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss36i.obj: ../fonts/fontcmss36i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss38.obj: ../fonts/fontcmss38.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss38b.obj: ../fonts/fontcmss38b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss38i.obj: ../fonts/fontcmss38i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss40.obj: ../fonts/fontcmss40.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss40b.obj: ../fonts/fontcmss40b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss40i.obj: ../fonts/fontcmss40i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss42.obj: ../fonts/fontcmss42.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss42b.obj: ../fonts/fontcmss42b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss42i.obj: ../fonts/fontcmss42i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss44.obj: ../fonts/fontcmss44.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss44b.obj: ../fonts/fontcmss44b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss44i.obj: ../fonts/fontcmss44i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss46.obj: ../fonts/fontcmss46.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss46b.obj: ../fonts/fontcmss46b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss46i.obj: ../fonts/fontcmss46i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss48.obj: ../fonts/fontcmss48.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss48b.obj: ../fonts/fontcmss48b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmss48i.obj: ../fonts/fontcmss48i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmtt12.obj: ../fonts/fontcmtt12.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmtt14.obj: ../fonts/fontcmtt14.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmtt16.obj: ../fonts/fontcmtt16.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmtt18.obj: ../fonts/fontcmtt18.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmtt20.obj: ../fonts/fontcmtt20.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmtt22.obj: ../fonts/fontcmtt22.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmtt24.obj: ../fonts/fontcmtt24.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmtt26.obj: ../fonts/fontcmtt26.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmtt28.obj: ../fonts/fontcmtt28.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmtt30.obj: ../fonts/fontcmtt30.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmtt32.obj: ../fonts/fontcmtt32.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmtt34.obj: ../fonts/fontcmtt34.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmtt36.obj: ../fonts/fontcmtt36.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmtt38.obj: ../fonts/fontcmtt38.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmtt40.obj: ../fonts/fontcmtt40.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmtt42.obj: ../fonts/fontcmtt42.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmtt44.obj: ../fonts/fontcmtt44.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmtt46.obj: ../fonts/fontcmtt46.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontcmtt48.obj: ../fonts/fontcmtt48.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

fontfixed6x8.obj: ../fonts/fontfixed6x8.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

startup_msp432p401r_ccs.obj: ../ccs/startup_msp432p401r_ccs.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< --output_file=$@

main.obj: ../main.c
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

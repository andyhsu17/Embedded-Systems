SIMPLELINK_MSP432_SDK_INSTALL_DIR ?= $(abspath ../../../../../..)

include $(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/imports.mak

CC = "$(GCC_ARMCOMPILER)/bin/arm-none-eabi-gcc"
LNK = "$(GCC_ARMCOMPILER)/bin/arm-none-eabi-gcc"

OBJECTS = system_msp432p401r.obj Crystalfontz128x128_ST7735.obj HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.obj fontcm12.obj fontcm12b.obj fontcm12i.obj fontcm14.obj fontcm14b.obj fontcm14i.obj fontcm16.obj fontcm16b.obj fontcm16i.obj fontcm18.obj fontcm18b.obj fontcm18i.obj fontcm20.obj fontcm20b.obj fontcm20i.obj fontcm22.obj fontcm22b.obj fontcm22i.obj fontcm24.obj fontcm24b.obj fontcm24i.obj fontcm26.obj fontcm26b.obj fontcm26i.obj fontcm28.obj fontcm28b.obj fontcm28i.obj fontcm30.obj fontcm30b.obj fontcm30i.obj fontcm32.obj fontcm32b.obj fontcm32i.obj fontcm34.obj fontcm34b.obj fontcm34i.obj fontcm36.obj fontcm36b.obj fontcm36i.obj fontcm38.obj fontcm38b.obj fontcm38i.obj fontcm40.obj fontcm40b.obj fontcm40i.obj fontcm42.obj fontcm42b.obj fontcm42i.obj fontcm44.obj fontcm44b.obj fontcm44i.obj fontcm46.obj fontcm46b.obj fontcm46i.obj fontcm48.obj fontcm48b.obj fontcm48i.obj fontcmsc12.obj fontcmsc14.obj fontcmsc16.obj fontcmsc18.obj fontcmsc20.obj fontcmsc22.obj fontcmsc24.obj fontcmsc26.obj fontcmsc28.obj fontcmsc30.obj fontcmsc32.obj fontcmsc34.obj fontcmsc36.obj fontcmsc38.obj fontcmsc40.obj fontcmsc42.obj fontcmsc44.obj fontcmsc46.obj fontcmsc48.obj fontcmss12.obj fontcmss12b.obj fontcmss12i.obj fontcmss14.obj fontcmss14b.obj fontcmss14i.obj fontcmss16.obj fontcmss16b.obj fontcmss16i.obj fontcmss18.obj fontcmss18b.obj fontcmss18i.obj fontcmss20.obj fontcmss20b.obj fontcmss20i.obj fontcmss22.obj fontcmss22b.obj fontcmss22i.obj fontcmss24.obj fontcmss24b.obj fontcmss24i.obj fontcmss26.obj fontcmss26b.obj fontcmss26i.obj fontcmss28.obj fontcmss28b.obj fontcmss28i.obj fontcmss30.obj fontcmss30b.obj fontcmss30i.obj fontcmss32.obj fontcmss32b.obj fontcmss32i.obj fontcmss34.obj fontcmss34b.obj fontcmss34i.obj fontcmss36.obj fontcmss36b.obj fontcmss36i.obj fontcmss38.obj fontcmss38b.obj fontcmss38i.obj fontcmss40.obj fontcmss40b.obj fontcmss40i.obj fontcmss42.obj fontcmss42b.obj fontcmss42i.obj fontcmss44.obj fontcmss44b.obj fontcmss44i.obj fontcmss46.obj fontcmss46b.obj fontcmss46i.obj fontcmss48.obj fontcmss48b.obj fontcmss48i.obj fontcmtt12.obj fontcmtt14.obj fontcmtt16.obj fontcmtt18.obj fontcmtt20.obj fontcmtt22.obj fontcmtt24.obj fontcmtt26.obj fontcmtt28.obj fontcmtt30.obj fontcmtt32.obj fontcmtt34.obj fontcmtt36.obj fontcmtt38.obj fontcmtt40.obj fontcmtt42.obj fontcmtt44.obj fontcmtt46.obj fontcmtt48.obj fontfixed6x8.obj startup_msp432p401r_gcc.obj main.obj

NAME = boostxl_edumkii_joystick_msp432p401r

CFLAGS = -I.. "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source" "-I$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/third_party/CMSIS/Include" -D__MSP432P401R__ -DDeviceFamily_MSP432P401x -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -ffunction-sections -fdata-sections -g -gstrict-dwarf -Wall "-I$(GCC_ARMCOMPILER)/arm-none-eabi/include/newlib-nano" "-I$(GCC_ARMCOMPILER)/arm-none-eabi/include"

LFLAGS = "-L$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/grlib/gcc" -l:grlib.a -Wl,-T,../gcc/msp432p401r.lds "-Wl,-Map,$(NAME).map" "-L$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/display/lib" -l:display.am4fg "-L$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/drivers/lib" -l:drivers_msp432p401x.am4fg "-L$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/third_party/fatfs/lib" -l:fatfs.am4fg "-L$(SIMPLELINK_MSP432_SDK_INSTALL_DIR)/source/ti/devices/msp432p4xx/driverlib/gcc" -l:msp432p4xx_driverlib.a -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -static -Wl,--gc-sections "-L$(GCC_ARMCOMPILER)/arm-none-eabi/lib/thumb/v7e-m/fpv4-sp/hard" -lgcc -lc -lm -lnosys --specs=nano.specs

all: $(NAME).out

system_msp432p401r.obj: ../system_msp432p401r.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

Crystalfontz128x128_ST7735.obj: ../LcdDriver/Crystalfontz128x128_ST7735.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.obj: ../LcdDriver/HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm12.obj: ../fonts/fontcm12.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm12b.obj: ../fonts/fontcm12b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm12i.obj: ../fonts/fontcm12i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm14.obj: ../fonts/fontcm14.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm14b.obj: ../fonts/fontcm14b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm14i.obj: ../fonts/fontcm14i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm16.obj: ../fonts/fontcm16.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm16b.obj: ../fonts/fontcm16b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm16i.obj: ../fonts/fontcm16i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm18.obj: ../fonts/fontcm18.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm18b.obj: ../fonts/fontcm18b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm18i.obj: ../fonts/fontcm18i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm20.obj: ../fonts/fontcm20.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm20b.obj: ../fonts/fontcm20b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm20i.obj: ../fonts/fontcm20i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm22.obj: ../fonts/fontcm22.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm22b.obj: ../fonts/fontcm22b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm22i.obj: ../fonts/fontcm22i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm24.obj: ../fonts/fontcm24.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm24b.obj: ../fonts/fontcm24b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm24i.obj: ../fonts/fontcm24i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm26.obj: ../fonts/fontcm26.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm26b.obj: ../fonts/fontcm26b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm26i.obj: ../fonts/fontcm26i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm28.obj: ../fonts/fontcm28.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm28b.obj: ../fonts/fontcm28b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm28i.obj: ../fonts/fontcm28i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm30.obj: ../fonts/fontcm30.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm30b.obj: ../fonts/fontcm30b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm30i.obj: ../fonts/fontcm30i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm32.obj: ../fonts/fontcm32.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm32b.obj: ../fonts/fontcm32b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm32i.obj: ../fonts/fontcm32i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm34.obj: ../fonts/fontcm34.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm34b.obj: ../fonts/fontcm34b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm34i.obj: ../fonts/fontcm34i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm36.obj: ../fonts/fontcm36.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm36b.obj: ../fonts/fontcm36b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm36i.obj: ../fonts/fontcm36i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm38.obj: ../fonts/fontcm38.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm38b.obj: ../fonts/fontcm38b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm38i.obj: ../fonts/fontcm38i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm40.obj: ../fonts/fontcm40.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm40b.obj: ../fonts/fontcm40b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm40i.obj: ../fonts/fontcm40i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm42.obj: ../fonts/fontcm42.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm42b.obj: ../fonts/fontcm42b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm42i.obj: ../fonts/fontcm42i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm44.obj: ../fonts/fontcm44.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm44b.obj: ../fonts/fontcm44b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm44i.obj: ../fonts/fontcm44i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm46.obj: ../fonts/fontcm46.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm46b.obj: ../fonts/fontcm46b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm46i.obj: ../fonts/fontcm46i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm48.obj: ../fonts/fontcm48.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm48b.obj: ../fonts/fontcm48b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcm48i.obj: ../fonts/fontcm48i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmsc12.obj: ../fonts/fontcmsc12.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmsc14.obj: ../fonts/fontcmsc14.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmsc16.obj: ../fonts/fontcmsc16.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmsc18.obj: ../fonts/fontcmsc18.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmsc20.obj: ../fonts/fontcmsc20.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmsc22.obj: ../fonts/fontcmsc22.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmsc24.obj: ../fonts/fontcmsc24.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmsc26.obj: ../fonts/fontcmsc26.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmsc28.obj: ../fonts/fontcmsc28.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmsc30.obj: ../fonts/fontcmsc30.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmsc32.obj: ../fonts/fontcmsc32.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmsc34.obj: ../fonts/fontcmsc34.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmsc36.obj: ../fonts/fontcmsc36.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmsc38.obj: ../fonts/fontcmsc38.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmsc40.obj: ../fonts/fontcmsc40.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmsc42.obj: ../fonts/fontcmsc42.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmsc44.obj: ../fonts/fontcmsc44.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmsc46.obj: ../fonts/fontcmsc46.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmsc48.obj: ../fonts/fontcmsc48.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss12.obj: ../fonts/fontcmss12.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss12b.obj: ../fonts/fontcmss12b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss12i.obj: ../fonts/fontcmss12i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss14.obj: ../fonts/fontcmss14.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss14b.obj: ../fonts/fontcmss14b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss14i.obj: ../fonts/fontcmss14i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss16.obj: ../fonts/fontcmss16.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss16b.obj: ../fonts/fontcmss16b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss16i.obj: ../fonts/fontcmss16i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss18.obj: ../fonts/fontcmss18.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss18b.obj: ../fonts/fontcmss18b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss18i.obj: ../fonts/fontcmss18i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss20.obj: ../fonts/fontcmss20.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss20b.obj: ../fonts/fontcmss20b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss20i.obj: ../fonts/fontcmss20i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss22.obj: ../fonts/fontcmss22.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss22b.obj: ../fonts/fontcmss22b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss22i.obj: ../fonts/fontcmss22i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss24.obj: ../fonts/fontcmss24.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss24b.obj: ../fonts/fontcmss24b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss24i.obj: ../fonts/fontcmss24i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss26.obj: ../fonts/fontcmss26.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss26b.obj: ../fonts/fontcmss26b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss26i.obj: ../fonts/fontcmss26i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss28.obj: ../fonts/fontcmss28.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss28b.obj: ../fonts/fontcmss28b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss28i.obj: ../fonts/fontcmss28i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss30.obj: ../fonts/fontcmss30.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss30b.obj: ../fonts/fontcmss30b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss30i.obj: ../fonts/fontcmss30i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss32.obj: ../fonts/fontcmss32.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss32b.obj: ../fonts/fontcmss32b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss32i.obj: ../fonts/fontcmss32i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss34.obj: ../fonts/fontcmss34.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss34b.obj: ../fonts/fontcmss34b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss34i.obj: ../fonts/fontcmss34i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss36.obj: ../fonts/fontcmss36.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss36b.obj: ../fonts/fontcmss36b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss36i.obj: ../fonts/fontcmss36i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss38.obj: ../fonts/fontcmss38.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss38b.obj: ../fonts/fontcmss38b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss38i.obj: ../fonts/fontcmss38i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss40.obj: ../fonts/fontcmss40.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss40b.obj: ../fonts/fontcmss40b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss40i.obj: ../fonts/fontcmss40i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss42.obj: ../fonts/fontcmss42.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss42b.obj: ../fonts/fontcmss42b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss42i.obj: ../fonts/fontcmss42i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss44.obj: ../fonts/fontcmss44.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss44b.obj: ../fonts/fontcmss44b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss44i.obj: ../fonts/fontcmss44i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss46.obj: ../fonts/fontcmss46.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss46b.obj: ../fonts/fontcmss46b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss46i.obj: ../fonts/fontcmss46i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss48.obj: ../fonts/fontcmss48.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss48b.obj: ../fonts/fontcmss48b.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmss48i.obj: ../fonts/fontcmss48i.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmtt12.obj: ../fonts/fontcmtt12.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmtt14.obj: ../fonts/fontcmtt14.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmtt16.obj: ../fonts/fontcmtt16.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmtt18.obj: ../fonts/fontcmtt18.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmtt20.obj: ../fonts/fontcmtt20.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmtt22.obj: ../fonts/fontcmtt22.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmtt24.obj: ../fonts/fontcmtt24.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmtt26.obj: ../fonts/fontcmtt26.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmtt28.obj: ../fonts/fontcmtt28.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmtt30.obj: ../fonts/fontcmtt30.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmtt32.obj: ../fonts/fontcmtt32.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmtt34.obj: ../fonts/fontcmtt34.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmtt36.obj: ../fonts/fontcmtt36.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmtt38.obj: ../fonts/fontcmtt38.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmtt40.obj: ../fonts/fontcmtt40.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmtt42.obj: ../fonts/fontcmtt42.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmtt44.obj: ../fonts/fontcmtt44.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmtt46.obj: ../fonts/fontcmtt46.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontcmtt48.obj: ../fonts/fontcmtt48.c
	@ echo Building $@
	@ $(CC) $(CFLAGS) $< -c -o $@

fontfixed6x8.obj: ../fonts/fontfixed6x8.c
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

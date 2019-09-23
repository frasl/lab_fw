##########################################################################################################################
# File automatically-generated by tool: [projectgenerator] version: [3.2.0] date: [Wed Aug 21 13:55:22 MSK 2019] 
##########################################################################################################################

# ------------------------------------------------
# Generic Makefile (based on gcc)
#
# ChangeLog :
#	2017-02-10 - Several enhancements + project update mode
#   2015-07-22 - first version
# ------------------------------------------------

######################################
# target
######################################
TARGET = LabTest


######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Og


#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

######################################
# source
######################################
# C sources
CPP_SOURCES =  \
Core/Src/uart_command_manager.cpp \
Core/Src/main.cpp \
Core/Src/blinker.cpp \
Core/Src/command_handler.cpp \
Core/Src/mem.cpp \
Core/Src/errors.cpp 

C_SOURCES =  \
Core/Src/gpio.c \
Core/Src/stm32f2xx_it.c \
Core/Src/stm32f2xx_hal_msp.c \
USB_DEVICE/App/usb_device.c \
USB_DEVICE/App/usbd_desc.c \
USB_DEVICE/App/usbd_storage_if.c \
USB_DEVICE/Target/usbd_conf.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_pcd_ex.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_pcd.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_ll_usb.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_tim.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_tim_ex.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_rcc.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_rcc_ex.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_cortex.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_flash.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_flash_ex.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_pwr.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_pwr_ex.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_gpio.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_dma.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_dma_ex.c \
Core/Src/system_stm32f2xx.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Src/usbd_msc.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Src/usbd_msc_bot.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Src/usbd_msc_data.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Src/usbd_msc_scsi.c \
Core/Src/fsmc.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_ll_fsmc.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_nand.c \
Core/Src/usart.c \
C:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Src/stm32f2xx_hal_uart.c

# ASM sources
ASM_SOURCES =  \
startup_stm32f207xx.s


#######################################
# binaries
#######################################
PREFIX = arm-none-eabi-
# The gcc compiler bin path can be either defined in make command via GCC_PATH variable (> make GCC_PATH=xxx)
# either it can be added to the PATH environment variable.
ifdef GCC_PATH
CC = $(GCC_PATH)/$(PREFIX)gcc
CPP = $(GCC_PATH)/$(PREFIX)g++
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
else
CC = $(PREFIX)gcc
CPP = $(PREFIX)g++
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
endif
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
 
#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m3

# fpu
# NONE for Cortex-M0/M0+/M3

# float-abi


# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS = 

# C defines
C_DEFS =  \
-DUSE_HAL_DRIVER \
-DSTM32F207xx


# AS includes
AS_INCLUDES = 

# C includes
C_INCLUDES =  \
-ICore/Inc \
-IUSB_DEVICE/App \
-IUSB_DEVICE/Target \
-IC:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Inc \
-IC:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/STM32F2xx_HAL_Driver/Inc/Legacy \
-IC:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Middlewares/ST/STM32_USB_Device_Library/Core/Inc \
-IC:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc \
-IC:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/CMSIS/Device/ST/STM32F2xx/Include \
-IC:/Users/S2400121/STM32Cube/Repository/STM32Cube_FW_F2_V1.7.0/Drivers/CMSIS/Include

# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections 

CPPFLAGS = $(CFLAGS) -fpermissive

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif


# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = STM32F207VETx_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys -lstdc++
LIBDIR = 
LDFLAGS = $(MCU) -specs=nano.specs -specs=nosys.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin


#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(CPP_SOURCES:.cpp=.o)))
vpath %.cpp $(sort $(dir $(CPP_SOURCES)))


$(BUILD_DIR)/%.o: %.cpp Makefile | $(BUILD_DIR) 
	$(info compiling $<)
	@$(CPP) -c $(CPPFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.cpp=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(info compiling $<)
	@$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir $@		

#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)
  
#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)

# *** EOF ***
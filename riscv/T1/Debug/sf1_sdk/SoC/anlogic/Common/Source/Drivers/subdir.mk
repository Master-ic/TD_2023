################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../sf1_sdk/SoC/anlogic/Common/Source/Drivers/anl_printf.c \
../sf1_sdk/SoC/anlogic/Common/Source/Drivers/nuclei_gpio.c \
../sf1_sdk/SoC/anlogic/Common/Source/Drivers/nuclei_i2c.c \
../sf1_sdk/SoC/anlogic/Common/Source/Drivers/nuclei_misc.c \
../sf1_sdk/SoC/anlogic/Common/Source/Drivers/nuclei_qspi.c \
../sf1_sdk/SoC/anlogic/Common/Source/Drivers/nuclei_uart.c 

OBJS += \
./sf1_sdk/SoC/anlogic/Common/Source/Drivers/anl_printf.o \
./sf1_sdk/SoC/anlogic/Common/Source/Drivers/nuclei_gpio.o \
./sf1_sdk/SoC/anlogic/Common/Source/Drivers/nuclei_i2c.o \
./sf1_sdk/SoC/anlogic/Common/Source/Drivers/nuclei_misc.o \
./sf1_sdk/SoC/anlogic/Common/Source/Drivers/nuclei_qspi.o \
./sf1_sdk/SoC/anlogic/Common/Source/Drivers/nuclei_uart.o 

C_DEPS += \
./sf1_sdk/SoC/anlogic/Common/Source/Drivers/anl_printf.d \
./sf1_sdk/SoC/anlogic/Common/Source/Drivers/nuclei_gpio.d \
./sf1_sdk/SoC/anlogic/Common/Source/Drivers/nuclei_i2c.d \
./sf1_sdk/SoC/anlogic/Common/Source/Drivers/nuclei_misc.d \
./sf1_sdk/SoC/anlogic/Common/Source/Drivers/nuclei_qspi.d \
./sf1_sdk/SoC/anlogic/Common/Source/Drivers/nuclei_uart.d 


# Each subdirectory must supply rules for building sources it contributes
sf1_sdk/SoC/anlogic/Common/Source/Drivers/%.o: ../sf1_sdk/SoC/anlogic/Common/Source/Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv-nuclei-elf-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -mno-save-restore -O0 -ffunction-sections -fdata-sections -fno-common  -g -DDOWNLOAD_MODE=DOWNLOAD_MODE_WORK3 -I"F:\al\sf1_-project-master\sf1_-project-master\src\GPIO_LED\riscv_project\T1\sf1_sdk\SoC\anlogic\Board\sf1_eval\Include" -I"F:\al\sf1_-project-master\sf1_-project-master\src\GPIO_LED\riscv_project\T1\application" -I"F:\al\sf1_-project-master\sf1_-project-master\src\GPIO_LED\riscv_project\T1\sf1_sdk\NMSIS\Core\Include" -I"F:\al\sf1_-project-master\sf1_-project-master\src\GPIO_LED\riscv_project\T1\sf1_sdk\SoC\anlogic\Common\Include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



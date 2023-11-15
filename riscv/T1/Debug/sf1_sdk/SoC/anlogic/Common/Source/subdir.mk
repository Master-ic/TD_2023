################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../sf1_sdk/SoC/anlogic/Common/Source/nuclei_common.c \
../sf1_sdk/SoC/anlogic/Common/Source/system_nuclei.c 

OBJS += \
./sf1_sdk/SoC/anlogic/Common/Source/nuclei_common.o \
./sf1_sdk/SoC/anlogic/Common/Source/system_nuclei.o 

C_DEPS += \
./sf1_sdk/SoC/anlogic/Common/Source/nuclei_common.d \
./sf1_sdk/SoC/anlogic/Common/Source/system_nuclei.d 


# Each subdirectory must supply rules for building sources it contributes
sf1_sdk/SoC/anlogic/Common/Source/%.o: ../sf1_sdk/SoC/anlogic/Common/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv-nuclei-elf-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -mno-save-restore -O0 -ffunction-sections -fdata-sections -fno-common  -g -DDOWNLOAD_MODE=DOWNLOAD_MODE_WORK3 -I"F:\al\sf1_-project-master\sf1_-project-master\src\GPIO_LED\riscv_project\T1\sf1_sdk\SoC\anlogic\Board\sf1_eval\Include" -I"F:\al\sf1_-project-master\sf1_-project-master\src\GPIO_LED\riscv_project\T1\application" -I"F:\al\sf1_-project-master\sf1_-project-master\src\GPIO_LED\riscv_project\T1\sf1_sdk\NMSIS\Core\Include" -I"F:\al\sf1_-project-master\sf1_-project-master\src\GPIO_LED\riscv_project\T1\sf1_sdk\SoC\anlogic\Common\Include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



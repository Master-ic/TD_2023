################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../sf1_sdk/SoC/anlogic/Common/Source/GCC/intexc_anlogic.S \
../sf1_sdk/SoC/anlogic/Common/Source/GCC/startup_anlogic.S 

OBJS += \
./sf1_sdk/SoC/anlogic/Common/Source/GCC/intexc_anlogic.o \
./sf1_sdk/SoC/anlogic/Common/Source/GCC/startup_anlogic.o 

S_UPPER_DEPS += \
./sf1_sdk/SoC/anlogic/Common/Source/GCC/intexc_anlogic.d \
./sf1_sdk/SoC/anlogic/Common/Source/GCC/startup_anlogic.d 


# Each subdirectory must supply rules for building sources it contributes
sf1_sdk/SoC/anlogic/Common/Source/GCC/%.o: ../sf1_sdk/SoC/anlogic/Common/Source/GCC/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross Assembler'
	riscv-nuclei-elf-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -mno-save-restore -O0 -ffunction-sections -fdata-sections -fno-common  -g -x assembler-with-cpp -DDOWNLOAD_MODE=DOWNLOAD_MODE_WORK3 -I"F:\al\sf1_-project-master\sf1_-project-master\src\GPIO_LED\riscv_project\T1\sf1_sdk\SoC\anlogic\Board\sf1_eval\Include" -I"F:\al\sf1_-project-master\sf1_-project-master\src\GPIO_LED\riscv_project\T1\application" -I"F:\al\sf1_-project-master\sf1_-project-master\src\GPIO_LED\riscv_project\T1\sf1_sdk\NMSIS\Core\Include" -I"F:\al\sf1_-project-master\sf1_-project-master\src\GPIO_LED\riscv_project\T1\sf1_sdk\SoC\anlogic\Common\Include" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



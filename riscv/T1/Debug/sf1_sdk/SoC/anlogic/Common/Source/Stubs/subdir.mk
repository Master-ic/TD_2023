################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../sf1_sdk/SoC/anlogic/Common/Source/Stubs/close.c \
../sf1_sdk/SoC/anlogic/Common/Source/Stubs/fstat.c \
../sf1_sdk/SoC/anlogic/Common/Source/Stubs/gettimeofday.c \
../sf1_sdk/SoC/anlogic/Common/Source/Stubs/isatty.c \
../sf1_sdk/SoC/anlogic/Common/Source/Stubs/lseek.c \
../sf1_sdk/SoC/anlogic/Common/Source/Stubs/read.c \
../sf1_sdk/SoC/anlogic/Common/Source/Stubs/sbrk.c \
../sf1_sdk/SoC/anlogic/Common/Source/Stubs/write.c 

OBJS += \
./sf1_sdk/SoC/anlogic/Common/Source/Stubs/close.o \
./sf1_sdk/SoC/anlogic/Common/Source/Stubs/fstat.o \
./sf1_sdk/SoC/anlogic/Common/Source/Stubs/gettimeofday.o \
./sf1_sdk/SoC/anlogic/Common/Source/Stubs/isatty.o \
./sf1_sdk/SoC/anlogic/Common/Source/Stubs/lseek.o \
./sf1_sdk/SoC/anlogic/Common/Source/Stubs/read.o \
./sf1_sdk/SoC/anlogic/Common/Source/Stubs/sbrk.o \
./sf1_sdk/SoC/anlogic/Common/Source/Stubs/write.o 

C_DEPS += \
./sf1_sdk/SoC/anlogic/Common/Source/Stubs/close.d \
./sf1_sdk/SoC/anlogic/Common/Source/Stubs/fstat.d \
./sf1_sdk/SoC/anlogic/Common/Source/Stubs/gettimeofday.d \
./sf1_sdk/SoC/anlogic/Common/Source/Stubs/isatty.d \
./sf1_sdk/SoC/anlogic/Common/Source/Stubs/lseek.d \
./sf1_sdk/SoC/anlogic/Common/Source/Stubs/read.d \
./sf1_sdk/SoC/anlogic/Common/Source/Stubs/sbrk.d \
./sf1_sdk/SoC/anlogic/Common/Source/Stubs/write.d 


# Each subdirectory must supply rules for building sources it contributes
sf1_sdk/SoC/anlogic/Common/Source/Stubs/%.o: ../sf1_sdk/SoC/anlogic/Common/Source/Stubs/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv-nuclei-elf-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -mno-save-restore -O0 -ffunction-sections -fdata-sections -fno-common  -g -DDOWNLOAD_MODE=DOWNLOAD_MODE_WORK3 -I"F:\al\sf1_-project-master\sf1_-project-master\src\GPIO_LED\riscv_project\T1\sf1_sdk\SoC\anlogic\Board\sf1_eval\Include" -I"F:\al\sf1_-project-master\sf1_-project-master\src\GPIO_LED\riscv_project\T1\application" -I"F:\al\sf1_-project-master\sf1_-project-master\src\GPIO_LED\riscv_project\T1\sf1_sdk\NMSIS\Core\Include" -I"F:\al\sf1_-project-master\sf1_-project-master\src\GPIO_LED\riscv_project\T1\sf1_sdk\SoC\anlogic\Common\Include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



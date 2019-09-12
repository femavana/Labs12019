################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Clase_06.c \
../src/arrays.c \
../src/get_Input.c 

OBJS += \
./src/Clase_06.o \
./src/arrays.o \
./src/get_Input.o 

C_DEPS += \
./src/Clase_06.d \
./src/arrays.d \
./src/get_Input.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Technical/Device/Device.cpp 

OBJS += \
./src/Technical/Device/Device.o 

CPP_DEPS += \
./src/Technical/Device/Device.d 


# Each subdirectory must supply rules for building sources it contributes
src/Technical/Device/%.o: ../src/Technical/Device/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



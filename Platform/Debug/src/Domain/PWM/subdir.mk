################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Domain/PWM/PWM.cpp 

OBJS += \
./src/Domain/PWM/PWM.o 

CPP_DEPS += \
./src/Domain/PWM/PWM.d 


# Each subdirectory must supply rules for building sources it contributes
src/Domain/PWM/%.o: ../src/Domain/PWM/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



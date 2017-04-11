################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Framework/Main/LifecycleManager.cpp 

OBJS += \
./src/Framework/Main/LifecycleManager.o 

CPP_DEPS += \
./src/Framework/Main/LifecycleManager.d 


# Each subdirectory must supply rules for building sources it contributes
src/Framework/Main/%.o: ../src/Framework/Main/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



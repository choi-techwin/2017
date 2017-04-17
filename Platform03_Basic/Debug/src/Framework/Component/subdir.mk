################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Framework/Component/Component.cpp 

OBJS += \
./src/Framework/Component/Component.o 

CPP_DEPS += \
./src/Framework/Component/Component.d 


# Each subdirectory must supply rules for building sources it contributes
src/Framework/Component/%.o: ../src/Framework/Component/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



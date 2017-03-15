################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Framework/Main/LifecycleManager.cpp \
../src/Framework/Main/Main.cpp 

OBJS += \
./src/Framework/Main/LifecycleManager.o \
./src/Framework/Main/Main.o 

CPP_DEPS += \
./src/Framework/Main/LifecycleManager.d \
./src/Framework/Main/Main.d 


# Each subdirectory must supply rules for building sources it contributes
src/Framework/Main/%.o: ../src/Framework/Main/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Application/S300/LifecycleManagerApp.cpp \
../src/Application/S300/Main.cpp 

OBJS += \
./src/Application/S300/LifecycleManagerApp.o \
./src/Application/S300/Main.o 

CPP_DEPS += \
./src/Application/S300/LifecycleManagerApp.d \
./src/Application/S300/Main.d 


# Each subdirectory must supply rules for building sources it contributes
src/Application/S300/%.o: ../src/Application/S300/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



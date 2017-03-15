################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Controller.cpp \
../src/Main.cpp \
../src/TrafficLight.cpp \
../src/TrafficLightState.cpp 

OBJS += \
./src/Controller.o \
./src/Main.o \
./src/TrafficLight.o \
./src/TrafficLightState.o 

CPP_DEPS += \
./src/Controller.d \
./src/Main.d \
./src/TrafficLight.d \
./src/TrafficLightState.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



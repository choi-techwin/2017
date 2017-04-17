################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Framework/Scheduler/Event.cpp \
../src/Framework/Scheduler/MainScheduler.cpp \
../src/Framework/Scheduler/Scheduler.cpp 

OBJS += \
./src/Framework/Scheduler/Event.o \
./src/Framework/Scheduler/MainScheduler.o \
./src/Framework/Scheduler/Scheduler.o 

CPP_DEPS += \
./src/Framework/Scheduler/Event.d \
./src/Framework/Scheduler/MainScheduler.d \
./src/Framework/Scheduler/Scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
src/Framework/Scheduler/%.o: ../src/Framework/Scheduler/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



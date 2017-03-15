################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Preset.cpp \
../src/Sequence.cpp \
../src/SequenceManager.cpp 

OBJS += \
./src/Preset.o \
./src/Sequence.o \
./src/SequenceManager.o 

CPP_DEPS += \
./src/Preset.d \
./src/Sequence.d \
./src/SequenceManager.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



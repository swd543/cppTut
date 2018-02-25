################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CppBasicsTut2.cpp 

OBJS += \
./src/CppBasicsTut2.o 

CPP_DEPS += \
./src/CppBasicsTut2.d 


# Each subdirectory must supply rules for building sources it contributes
src/CppBasicsTut2.o: ../src/CppBasicsTut2.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -std=gnu++17 -O1 -g3 -Wall -c -fmessage-length=0 -v -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/CppBasicsTut2.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



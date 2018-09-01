################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Calendar.cpp \
../src/PageApp.cpp \
../src/PageFrame.cpp \
../src/main.cpp 

OBJS += \
./src/Calendar.o \
./src/PageApp.o \
./src/PageFrame.o \
./src/main.o 

CPP_DEPS += \
./src/Calendar.d \
./src/PageApp.d \
./src/PageFrame.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++  -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXMSW__ -I"D:\Workspace\cplusplus\Learn\libs\WxWidget\include" -I"D:\Workspace\cplusplus\Learn\libs\WxBuild\lib\wx\include\msw-unicode-3.1" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



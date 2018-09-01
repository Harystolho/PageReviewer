################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/page/Day.cpp \
../src/page/Month.cpp \
../src/page/Year.cpp \
../src/page/post.cpp 

OBJS += \
./src/page/Day.o \
./src/page/Month.o \
./src/page/Year.o \
./src/page/post.o 

CPP_DEPS += \
./src/page/Day.d \
./src/page/Month.d \
./src/page/Year.d \
./src/page/post.d 


# Each subdirectory must supply rules for building sources it contributes
src/page/%.o: ../src/page/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++  -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXMSW__ -I"D:\Workspace\cplusplus\Learn\libs\WxWidget\include" -I"D:\Workspace\cplusplus\Learn\libs\WxBuild\lib\wx\include\msw-unicode-3.1" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



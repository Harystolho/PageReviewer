################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/windows/AddPostWindow.cpp \
../src/windows/PageScrollBox.cpp \
../src/windows/PostAdapter.cpp 

OBJS += \
./src/windows/AddPostWindow.o \
./src/windows/PageScrollBox.o \
./src/windows/PostAdapter.o 

CPP_DEPS += \
./src/windows/AddPostWindow.d \
./src/windows/PageScrollBox.d \
./src/windows/PostAdapter.d 


# Each subdirectory must supply rules for building sources it contributes
src/windows/%.o: ../src/windows/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++  -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXMSW__ -I"D:\Workspace\cplusplus\Learn\libs\WxWidget\include" -I"D:\Workspace\cplusplus\Learn\libs\WxBuild\lib\wx\include\msw-unicode-3.1" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



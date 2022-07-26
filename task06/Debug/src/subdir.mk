################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/display_tree.c \
../src/main.c \
../src/person_utilities.c \
../src/unique_person_id.c 

C_DEPS += \
./src/display_tree.d \
./src/main.d \
./src/person_utilities.d \
./src/unique_person_id.d 

OBJS += \
./src/display_tree.o \
./src/main.o \
./src/person_utilities.o \
./src/unique_person_id.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/display_tree.d ./src/display_tree.o ./src/main.d ./src/main.o ./src/person_utilities.d ./src/person_utilities.o ./src/unique_person_id.d ./src/unique_person_id.o

.PHONY: clean-src


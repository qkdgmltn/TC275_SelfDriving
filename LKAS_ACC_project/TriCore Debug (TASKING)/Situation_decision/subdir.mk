################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Situation_decision/AppScheduling.c \
../Situation_decision/Driver_Stm.c \
../Situation_decision/debug_UART.c 

COMPILED_SRCS += \
./Situation_decision/AppScheduling.src \
./Situation_decision/Driver_Stm.src \
./Situation_decision/debug_UART.src 

C_DEPS += \
./Situation_decision/AppScheduling.d \
./Situation_decision/Driver_Stm.d \
./Situation_decision/debug_UART.d 

OBJS += \
./Situation_decision/AppScheduling.o \
./Situation_decision/Driver_Stm.o \
./Situation_decision/debug_UART.o 


# Each subdirectory must supply rules for building sources it contributes
Situation_decision/%.src: ../Situation_decision/%.c Situation_decision/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc27xd "-fC:/Users/USER/AURIX-v1.9.20-workspace/TC275_SelfDriving/LKAS_ACC_project/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc27xd -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/Situation_decision\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

Situation_decision/AppScheduling.o: ./Situation_decision/AppScheduling.src Situation_decision/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Situation_decision/Driver_Stm.o: ./Situation_decision/Driver_Stm.src Situation_decision/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Situation_decision/debug_UART.o: ./Situation_decision/debug_UART.src Situation_decision/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Situation_decision

clean-Situation_decision:
	-$(RM) ./Situation_decision/AppScheduling.d ./Situation_decision/AppScheduling.o ./Situation_decision/AppScheduling.src ./Situation_decision/Driver_Stm.d ./Situation_decision/Driver_Stm.o ./Situation_decision/Driver_Stm.src ./Situation_decision/debug_UART.d ./Situation_decision/debug_UART.o ./Situation_decision/debug_UART.src

.PHONY: clean-Situation_decision


################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC27D/Tricore/Asclin/Asc/IfxAsclin_Asc.c 

COMPILED_SRCS += \
./Libraries/iLLD/TC27D/Tricore/Asclin/Asc/IfxAsclin_Asc.src 

C_DEPS += \
./Libraries/iLLD/TC27D/Tricore/Asclin/Asc/IfxAsclin_Asc.d 

OBJS += \
./Libraries/iLLD/TC27D/Tricore/Asclin/Asc/IfxAsclin_Asc.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC27D/Tricore/Asclin/Asc/%.src: ../Libraries/iLLD/TC27D/Tricore/Asclin/Asc/%.c Libraries/iLLD/TC27D/Tricore/Asclin/Asc/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc27xd "-fC:/Users/user/AURIX-v1.9.20-workspace/TC275_SelfDriving/LKAS_ACC_project/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc27xd -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/Libraries\/iLLD\/TC27D\/Tricore\/Asclin\/Asc\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

Libraries/iLLD/TC27D/Tricore/Asclin/Asc/IfxAsclin_Asc.o: ./Libraries/iLLD/TC27D/Tricore/Asclin/Asc/IfxAsclin_Asc.src Libraries/iLLD/TC27D/Tricore/Asclin/Asc/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Libraries-2f-iLLD-2f-TC27D-2f-Tricore-2f-Asclin-2f-Asc

clean-Libraries-2f-iLLD-2f-TC27D-2f-Tricore-2f-Asclin-2f-Asc:
	-$(RM) ./Libraries/iLLD/TC27D/Tricore/Asclin/Asc/IfxAsclin_Asc.d ./Libraries/iLLD/TC27D/Tricore/Asclin/Asc/IfxAsclin_Asc.o ./Libraries/iLLD/TC27D/Tricore/Asclin/Asc/IfxAsclin_Asc.src

.PHONY: clean-Libraries-2f-iLLD-2f-TC27D-2f-Tricore-2f-Asclin-2f-Asc


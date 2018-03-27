################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
functions.obj: ../functions.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"E:/software packs/CCS7.4.0.00015_win32/ti-cgt-c6000_8.2.2/bin/cl6x" -mv6740 --include_path="E:/1thesis/demo/PD" --include_path="E:/software packs/CCS7.4.0.00015_win32/ti-cgt-c6000_8.2.2/include" --define=c6748 -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="functions.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"E:/software packs/CCS7.4.0.00015_win32/ti-cgt-c6000_8.2.2/bin/cl6x" -mv6740 --include_path="E:/1thesis/demo/PD" --include_path="E:/software packs/CCS7.4.0.00015_win32/ti-cgt-c6000_8.2.2/include" --define=c6748 -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="main.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '



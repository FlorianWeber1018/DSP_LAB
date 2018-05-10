################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
build-551357505: ../BIOS_config.tcf
	@echo 'Building file: $<'
	@echo 'Invoking: TConf'
	"C:/ti/bios_5_42_02_10/xdctools/tconf" -b -Dconfig.importPath="C:/ti/bios_5_42_02_10/packages;" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BIOS_configcfg.cmd: build-551357505
BIOS_configcfg.s??: build-551357505
BIOS_configcfg_c.c: build-551357505
BIOS_configcfg.h: build-551357505
BIOS_configcfg.h??: build-551357505
BIOS_config.cdb: build-551357505

BIOS_configcfg.obj: ./BIOS_configcfg.s?? $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c6000_7.4.18/bin/cl6x" -mv6700 --abi=coffabi -O2 --include_path="C:/ti/ccsv6/tools/compiler/c6000_7.4.18/include" --include_path="C:/ti/DSK6713/c6000/dsk6713/include" --include_path="C:/ti/DSPLIB/c6700/dsplib/include" --include_path="C:/ti/C6xCSL/include" --include_path="C:/Users/dsplab/workspace_v6_2/DSPLAB/Release" --include_path="C:/ti/bios_5_42_02_10/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/rtdx/include/c6000" --define=c6713 --define=CHIP_6713 --diag_wrap=off --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="BIOS_configcfg.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

BIOS_configcfg_c.obj: ./BIOS_configcfg_c.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c6000_7.4.18/bin/cl6x" -mv6700 --abi=coffabi -O2 --include_path="C:/ti/ccsv6/tools/compiler/c6000_7.4.18/include" --include_path="C:/ti/DSK6713/c6000/dsk6713/include" --include_path="C:/ti/DSPLIB/c6700/dsplib/include" --include_path="C:/ti/C6xCSL/include" --include_path="C:/Users/dsplab/workspace_v6_2/DSPLAB/Release" --include_path="C:/ti/bios_5_42_02_10/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/rtdx/include/c6000" --define=c6713 --define=CHIP_6713 --diag_wrap=off --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="BIOS_configcfg_c.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

FirInt.obj: ../FirInt.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c6000_7.4.18/bin/cl6x" -mv6700 --abi=coffabi -O2 --include_path="C:/ti/ccsv6/tools/compiler/c6000_7.4.18/include" --include_path="C:/ti/DSK6713/c6000/dsk6713/include" --include_path="C:/ti/DSPLIB/c6700/dsplib/include" --include_path="C:/ti/C6xCSL/include" --include_path="C:/Users/dsplab/workspace_v6_2/DSPLAB/Release" --include_path="C:/ti/bios_5_42_02_10/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/rtdx/include/c6000" --define=c6713 --define=CHIP_6713 --diag_wrap=off --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="FirInt.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

config_AIC23.obj: ../config_AIC23.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c6000_7.4.18/bin/cl6x" -mv6700 --abi=coffabi -O2 --include_path="C:/ti/ccsv6/tools/compiler/c6000_7.4.18/include" --include_path="C:/ti/DSK6713/c6000/dsk6713/include" --include_path="C:/ti/DSPLIB/c6700/dsplib/include" --include_path="C:/ti/C6xCSL/include" --include_path="C:/Users/dsplab/workspace_v6_2/DSPLAB/Release" --include_path="C:/ti/bios_5_42_02_10/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/rtdx/include/c6000" --define=c6713 --define=CHIP_6713 --diag_wrap=off --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="config_AIC23.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

fastFolding.obj: ../fastFolding.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c6000_7.4.18/bin/cl6x" -mv6700 --abi=coffabi -O2 --include_path="C:/ti/ccsv6/tools/compiler/c6000_7.4.18/include" --include_path="C:/ti/DSK6713/c6000/dsk6713/include" --include_path="C:/ti/DSPLIB/c6700/dsplib/include" --include_path="C:/ti/C6xCSL/include" --include_path="C:/Users/dsplab/workspace_v6_2/DSPLAB/Release" --include_path="C:/ti/bios_5_42_02_10/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/rtdx/include/c6000" --define=c6713 --define=CHIP_6713 --diag_wrap=off --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="fastFolding.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

skeletonmod\ flo.obj: ../skeletonmod\ flo.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c6000_7.4.18/bin/cl6x" -mv6700 --abi=coffabi -O2 --include_path="C:/ti/ccsv6/tools/compiler/c6000_7.4.18/include" --include_path="C:/ti/DSK6713/c6000/dsk6713/include" --include_path="C:/ti/DSPLIB/c6700/dsplib/include" --include_path="C:/ti/C6xCSL/include" --include_path="C:/Users/dsplab/workspace_v6_2/DSPLAB/Release" --include_path="C:/ti/bios_5_42_02_10/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_02_10/packages/ti/rtdx/include/c6000" --define=c6713 --define=CHIP_6713 --diag_wrap=off --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="skeletonmod flo.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '



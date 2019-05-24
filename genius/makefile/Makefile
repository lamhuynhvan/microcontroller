#===================================================================================================
# The MIT License (MIT)
#
# Copyright
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software
# and associated documentation files (the "Software"), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify, merge, publish, distribute,
# sublicense, and/or sell copies of the Software, and to permit persons to whom the Software
# is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all copies
# or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
# BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
# AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
# DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
#
# Build system for C project
#===================================================================================================
# Revision History:
#                              Modification     Tracking
# Author (core ID)              Date D/M/Y       Number     Description of Changes
#---------------------------   ------------   ------------  ----------------------------------------
# Lam Huynh Van                 06/05/2019    ENGR11682     Initial version
#---------------------------   ------------   ------------  ----------------------------------------
#===================================================================================================

lc = $(subst A,a,$(subst B,b,$(subst C,c,$(subst D,d,$(subst E,e,$(subst F,f,$(subst G,g,$(subst H,h,$(subst I,i,$(subst J,j,$(subst K,k,$(subst L,l,$(subst M,m,$(subst N,n,$(subst O,o,$(subst P,p,$(subst Q,q,$(subst R,r,$(subst S,s,$(subst T,t,$(subst U,u,$(subst V,v,$(subst W,w,$(subst X,x,$(subst Y,y,$(subst Z,z,$1))))))))))))))))))))))))))

PROJ_DIR			:= ../../genius

include	$(PROJ_DIR)/makefile/local_config.mak

DERIVATIVE_NAME		:= $(DERIVATIVE)
MODULE_NAME			:= $(call lc,$(MODULE))
TEST_NAME			:= $(TEST)


TEST_DIR			:= $(PROJ_DIR)/test
HAL_DIR				:= $(PROJ_DIR)/hal
LIB_DIR				:= $(PROJ_DIR)/lib
PLATFORM_DIR		:= $(PROJ_DIR)/platform/derivative/$(DERIVATIVE_NAME)

# Output building folder
OUTPUT_PATH 		:= ./output/test_$(MODULE_NAME)/$(TEST_NAME)

include $(TEST_DIR)/test_$(MODULE_NAME)/make/$(TEST_NAME).mak

# Include folders:
INC_DIRS			+= $(HAL_DIR)/common/inc
INC_DIRS			+= $(HAL_DIR)/clock/inc
INC_DIRS			+= $(HAL_DIR)/gpio/inc
INC_DIRS			+= $(HAL_DIR)/interrupt/inc
INC_DIRS			+= $(HAL_DIR)/systick/inc
INC_DIRS			+= $(HAL_DIR)/usart/inc
INC_DIRS			+= $(LIB_DIR)/cli/inc
INC_DIRS			+= $(LIB_DIR)/common/inc

# List folder contains C language files
SRC_DIRS			+= $(HAL_DIR)/clock/src
SRC_DIRS			+= $(HAL_DIR)/gpio/src
SRC_DIRS			+= $(HAL_DIR)/interrupt/src
SRC_DIRS			+= $(HAL_DIR)/systick/src
SRC_DIRS			+= $(HAL_DIR)/usart/src
SRC_DIRS			+= $(LIB_DIR)/cli/src
SRC_DIRS			+= $(LIB_DIR)/common/src
SRC_DIRS			+= $(PLATFORM_DIR)/startup

# List folder contains ASM language files
ASM_DIRS			+= $(PLATFORM_DIR)/startup

# Linker file
LINKER_FILE			:= $(PLATFORM_DIR)/linker/stm32f0.ld

# Setting compiler option
CC_OPT				= -march=armv6-m -mcpu=cortex-m0 -c -g -mthumb $(INC_DIR) -DCLI_STAND_ALONE
ASM_OPT				= -march=armv6-m -mcpu=cortex-m0 -c -mthumb --defsym __STARTUP_CLEAR_BSS=1 --defsym __STACK_SIZE=0x300 --defsym __HEAP_SIZE=0x800
LD_OPT				= -T $(LINKER_FILE) -Map $(OUTPUT_PATH)/$(TEST_NAME).map $(OBJECT_FILE) -L $(COMPILER_DIR)/arm-none-eabi/lib/thumb/v6-m -lc_nano -lnosys

# Include build system to use common taget rules:
BUILD_SYSTEM		:= $(PROJ_DIR)/makefile
include	$(BUILD_SYSTEM)/common.mak

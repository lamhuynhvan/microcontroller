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

# Compiler
COMPILER_DIR		:= $(GCC_COMPILER)

# List of C language files:
SRC_FILES			+= $(foreach __dir,$(SRC_DIRS),$(wildcard $(__dir)/*.c))

# List of ASM language files:
ASM_FILES			+= $(foreach __dir,$(ASM_DIRS),$(wildcard $(__dir)/*.s))
ASM_FILES			+= $(foreach __dir,$(ASM_DIRS),$(wildcard $(__dir)/*.S))

# Include folder
INC_DIR				= $(foreach __dir,$(INC_DIRS),$(addprefix -I , $(__dir)))

PREFIX_GCC_COMPILER	:= arm-none-eabi
CC					:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-gcc
ASM					:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-as
LD					:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-ld
SIZE				:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-size
OBJCPY				:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-objcopy
NM					:= $(COMPILER_DIR)/bin/$(PREFIX_GCC_COMPILER)-nm

BUILD_FILE			= $(SRC_FILES) $(ASM_FILES)
OBJECT_FILE			= $(addprefix $(OUTPUT_PATH)/,$(addsuffix .o,$(basename $(notdir $(BUILD_FILE)))))
DEPS 				= $(OBJECT_FILE:.o=.d)

.PHONY: all

all: clean build hex size

# Generate object file of c file
ifndef generate_c_rule
define generate_c_rule
$(addprefix $(OUTPUT_PATH)/,$(addsuffix .o,$(basename $(notdir $(1))))): $(1)
	@echo Processing $$<
	$(CC) $(CC_OPT) $$< -o $$@
endef
endif # generate_c_rule

# Generate object file of c file
ifndef generate_asm_rule
define generate_asm_rule
$(addprefix $(OUTPUT_PATH)/,$(addsuffix .o,$(basename $(notdir $(1))))): $(1)
	@echo Processing $$<
	$(ASM) $(ASM_OPT) $$< -o $$@
endef
endif # generate_asm_rule

# Generate all c and asm file of project
$(foreach file,$(SRC_FILES),$(eval $(call generate_c_rule,$(file))))
$(foreach file,$(ASM_FILES),$(eval $(call generate_asm_rule,$(file))))

size: $(OUTPUT_PATH)/$(TEST_NAME).elf
	@echo "Size area memories in binary image $(OUTPUT_PATH)/$(TEST_NAME).elf"
	$(SIZE) $(OUTPUT_PATH)/$(TEST_NAME).elf

d_size: $(OUTPUT_PATH)/$(TEST_NAME).elf
	$(NM) --demangle --print-size --size-sort --reverse-sort -S $(OUTPUT_PATH)/$(TEST_NAME).elf

show_flag:
	@echo "\r\nSRC_DIRS :"
	@echo $(SRC_DIRS)
	@echo "\r\nSRC_FILES :"
	@echo $(SRC_FILES)
	@echo "\r\nASM_DIRS :"
	@echo $(ASM_DIRS)
	@echo "\r\nASM_FILES :"
	@echo $(ASM_FILES)
	@echo "\r\nINC_DIR :"
	@echo $(INC_DIR)
	@echo "\r\nOBJECT_FILE :"
	@echo $(OBJECT_FILE)
	@echo "\r\nCC_OPT :"
	@echo $(CC_OPT)
	@echo "\r\nASM_OPT :"
	@echo $(ASM_OPT)
	@echo "\r\nLD_OPT :"
	@echo $(LD_OPT)
	@echo "\r\nOUTPUT_PATH :"
	@echo $(OUTPUT_PATH)
	@echo "\r\n"

hex: $(OUTPUT_PATH)/$(TEST_NAME).elf
	$(OBJCPY) -O ihex $(OUTPUT_PATH)/$(TEST_NAME).elf $(OUTPUT_PATH)/$(TEST_NAME).hex

build: $(OBJECT_FILE)
	@echo "Linking object files to create new binary image $(OUTPUT_PATH)/$(TEST_NAME).elf"
	$(LD) $(LD_OPT) -o $(OUTPUT_PATH)/$(TEST_NAME).elf

clean:
	@rm -rf $(OUTPUT_PATH)

generate:
	@mkdir -pv $(OUTPUT_PATH)

info:
	@find $(TEST_DIR)/test_$(MODULE_NAME)/make/gpio_*.mak

-include $(DEPS)

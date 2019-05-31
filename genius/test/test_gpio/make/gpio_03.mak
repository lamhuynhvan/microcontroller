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

####################################################################################################
# List of all include directories (test, dependency, and generated .h files)
####################################################################################################
INC_DIRS			+= $(TEST_DIR)/test_$(MODULE_NAME)/include

####################################################################################################
# List of all source directories (test, dependency, and generated .c files)
####################################################################################################
# SRC_DIRS			+= $(TEST_DIR)/test_$(MODULE_NAME)/src

####################################################################################################
# List of source files
####################################################################################################
SRC_FILES			+= $(TEST_DIR)/test_$(MODULE_NAME)/src/gpio_03.c

################################################################################
# Additional test specific C compiler options
################################################################################
CC_OPT				+=

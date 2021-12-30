COMP = g++
BUILD_DIR = bin
UT_NAME = accounting_ut
UT = unittest/$(UT_NAME).cpp
UT_OBJ = $(BUILD_DIR)/$(UT_NAME).o

ACCOUNTNG_DIR = ./src/accounting
ACOUNTING_FILES = $(wildcard $(ACCOUNTNG_DIR)/*.cpp)
ACCOUNTING_OBJS = $(patsubst $(ACCOUNTNG_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(ACOUNTING_FILES))
C_INCLUDES = -Isrc/accounting
EXE_NAME = ut

all: $(ACCOUNTING_OBJS), to_bin

to_bin: 
	$(COMP) -o $(BUILD_DIR)/$(EXE_NAME) $(BUILD_DIR)/%.o

$(ACCOUNTING_OBJS): $(ACOUNTING_FILES)
	$(COMP) $(C_INCLUDES) -c $< -o $@  

$(UT_OBJ): $(UT)
	$(COMP) $(C_INCLUDES) -c $<-o $@  

clear_bin:
	del $(BUILD_DIR)\* /q  

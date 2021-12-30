COMP = g++
BUILD_DIR = bin
UT_NAME = accounting_ut
UT = unittest/$(UT_NAME).cpp
UT_OBJ = $(BUILD_DIR)/$(UT_NAME).o

ACCOUNTNG_DIR = ./src/accounting
ACCOUNTING_OBJS = $(patsubst $(ACCOUNTNG_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(ACOUNTING_FILES))
C_INCLUDES = -Isrc/accounting
EXE_NAME = ut
FINAL_EXE = $(BUILD_DIR)/$(EXE_NAME)

to_bin: 
	$(COMP) $(C_INCLUDES) -c $(BUILD_DIR)/*.o  -o $(FINAL_EXE)    

accounting_obj: $(BUILD_DIR)/%.o: $(ACCOUNTNG_DIR)/%.cpp
	$(COMP) $(C_INCLUDES) -c $< -o $@  

unit_test: $(UT_OBJ): $(UT)
	$(COMP) $(C_INCLUDES) -c $< -o $@  

clear_bin:
	del $(BUILD_DIR)\* /q  

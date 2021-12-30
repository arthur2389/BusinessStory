COMP = g++
BUILD_DIR = bin
UT_NAME = accounting_ut
UT = unittest/$(UT_NAME).cpp
UT_OBJ = $(BUILD_DIR)/$(UT_NAME).o
ACCOUNTNG_DIR = src/accounting
C_INCLUDES = -Isrc/accounting
FINAL_EXE = $(BUILD_DIR)/$(UT_NAME)

to_bin: 
	$(COMP) $(C_INCLUDES) -o $(FINAL_EXE) $(BUILD_DIR)/*.o    

loan_issuece:
	$(COMP) $(C_INCLUDES) -c $(ACCOUNTNG_DIR)/LoanIssuance.cpp -o $(BUILD_DIR)/LoanIssuance.o  

earnings:
	$(COMP) $(C_INCLUDES) -c $(ACCOUNTNG_DIR)/Earnings.cpp -o $(BUILD_DIR)/Earnings.o  

assets:
	$(COMP) $(C_INCLUDES) -c $(ACCOUNTNG_DIR)/Assets.cpp -o $(BUILD_DIR)/Assets.o  

unit_test:
	$(COMP) $(C_INCLUDES) -c $(UT) -o $(UT_OBJ)  

clear_bin:
	del $(BUILD_DIR)\* /q  

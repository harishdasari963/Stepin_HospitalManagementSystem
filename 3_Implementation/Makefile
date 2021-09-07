# Name of the project
PROJECT_NAME = hospital

# Name of the test project
TEST_PROJ_NAME = test_$(PROJECT_NAME)

# Output directory
BUILD = build

# All source code files
SRC = main.c\
src/hms.c\


# All test source files
TEST_SRC = src/hms.c\
test/test_hms.c\
unity/unity.c\


# Covrage source file
COV_SRC = test_hms.c

# All include folders with header files
INC	= -Iinc\
-Iunity\

#Library Inlcudes
#INCLUDE_LIBS = 
INCLUDE_LIBS = -lcunit

# Project Output name
PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).out

# Document files
DOCUMENTATION_OUTPUT = documentation/html

#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = rm -rf
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

# Default target built
$(PROJECT_NAME):all

# Run the target even if the matching name exists
.PHONY: run clean test doc all

all: $(SRC) $(BUILD)
	gcc $(SRC) $(INC) -o $(call FixPath,$(BUILD)/$(PROJECT_NAME).$(EXEC)) -lm

# Run in dev mode
dev: all
	$(call FixPath,$(BUILD)/$(PROJECT_NAME).$(EXEC)) dev 

# Call `make run` to run the application
run:$(PROJECT_NAME)
	$(call FixPath,$(BUILD)/$(PROJECT_NAME).$(EXEC))

# Document the code using Doxygen
doc:
	make -C ./documentation

# Build and run the unit tests
test:$(TEST_SRC) $(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD)/$(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath,$(BUILD)/$(TEST_PROJ_NAME).$(EXEC))

# Remove all the built files, invoke by `make clean`
clean:
	$(RM) $(call FixPath,$(BUILD))
	$(RM) $(call FixPath,$(DOCUMENTATION_OUTPUT))
	$(RM) $(call FixPath,$(PROJECT_NAME),$(PROJECT_NAME).gcno)

# Coverage
coverage:
	cp test/$(COV_SRC) .
	gcc -fprofile-arcs -ftest-coverage $(TEST_SRC) $(INC) -o $(call FixPath,./$(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath,./$(TEST_PROJ_NAME).$(EXEC))
	gcov -a $(COV_SRC)
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov
	$(RM) *.DAT
	$(RM) $(COV_SRC)

# Create new build folder if not present
$(BUILD):
	mkdir build

# Dynamic check
dynamic: $(TEST_SRC) $(BUILD)
	gcc -fsanitize=address -fno-omit-frame-pointer $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD)/$(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath,$(BUILD)/$(TEST_PROJ_NAME).$(EXEC))

# Static code analysis
cppcheck:
	cppcheck -i unity --enable=all .

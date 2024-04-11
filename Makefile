# Compiler & linker
CC              = g++
# Directory
SOURCE_FOLDER   = src/libs
OUTPUT_FOLDER   = bin
TEST_FOLDER 	= unitTest
TEST_OUTPUT_FOLDER = bin/Test
WARNING_CFLAG   = -Wall -Wextra -Werror
DEBUG_CFLAG     = -fshort-wchar -g
CFLAGS          = $(DEBUG_CFLAG) $(WARNING_CFLAG)
EXECUTABLE_FILENAME = Walaoeh

# Find all source files recursively
ALL_SRCS := $(filter-out $(SOURCE_FOLDER)/Bangunan/main.cpp $(SOURCE_FOLDER)/Hewan/main.cpp $(SOURCE_FOLDER)/Tanaman/main.cpp $(SOURCE_FOLDER)/ProdukHewan/main.cpp ,$(wildcard $(SOURCE_FOLDER)/*/*.cpp $(SOURCE_FOLDER)/*/*/*.cpp $(SOURCE_FOLDER)/pcolor/pcolor.c $(SOURCE_FOLDER)/Pemain/Storage/Storage.hpp))

# Create a list of object files from source files
OBJECTS := $(patsubst $(SOURCE_FOLDER)/%.cpp,$(OUTPUT_FOLDER)/%.o,$(ALL_SRCS))

# Main target to compile all sources and link them
compile: $(OBJECTS)
	@echo "Linking object files..."
	@$(CC) -std=c++17 -o $(OUTPUT_FOLDER)/$(EXECUTABLE_FILENAME) $(OBJECTS) ./src/main.cpp
	@echo "Compilation done."

# Compile each source file into an object file
$(OUTPUT_FOLDER)/%.o: $(SOURCE_FOLDER)/%.cpp
	@echo "Compiling $<..."
	@mkdir -p $(@D)
	@$(CC) -std=c++17 -c -o $@ $<

run:
	@./$(OUTPUT_FOLDER)/$(EXECUTABLE_FILENAME)

all: compile run

# For testing purposes
$(TEST_OUTPUT_FOLDER)/%: $(OBJECTS) $(TEST_FOLDER)/%.cpp
	@echo "Testing $*..."
	@mkdir -p $(TEST_OUTPUT_FOLDER)
	@$(CC)  -std=c++17 -o $@ $(OBJECTS) $(TEST_FOLDER)/$*.cpp

testBangunan: $(TEST_OUTPUT_FOLDER)/testBangunan
	@./$(TEST_OUTPUT_FOLDER)/testBangunan

testProdukHewan: $(TEST_OUTPUT_FOLDER)/testProdukHewan
	@./$(TEST_OUTPUT_FOLDER)/testProdukHewan

testHewan: $(TEST_OUTPUT_FOLDER)/testHewan
	@./$(TEST_OUTPUT_FOLDER)/testHewan

testParser: $(TEST_OUTPUT_FOLDER)/testParser
	@./$(TEST_OUTPUT_FOLDER)/testParser

testTanaman: $(TEST_OUTPUT_FOLDER)/testTanaman
	@./$(TEST_OUTPUT_FOLDER)/testTanaman

testStorage: $(TEST_OUTPUT_FOLDER)/testStorage
	@./$(TEST_OUTPUT_FOLDER)/testStorage

testGameWorld: $(TEST_OUTPUT_FOLDER)/testGameWorld
	@./$(TEST_OUTPUT_FOLDER)/testGameWorld
clean:
	@rm -rf $(OUTPUT_FOLDER)/*
	@echo "Clean done."

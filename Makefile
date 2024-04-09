# Compiler & linker
CC            = g++
# Directory
SOURCE_FOLDER = src/libs
OUTPUT_FOLDER = bin

WARNING_CFLAG = -Wall -Wextra -Werror
DEBUG_CFLAG   = -fshort-wchar -g
CFLAGS        = $(DEBUG_CFLAG) $(WARNING_CFLAG)
EXECUTABLE_FILENAME = Walaoeh
ALL_SRCS :=   $(filter-out $(SOURCE_FOLDER)/Bangunan/main.cpp $(SOURCE_FOLDER)/Hewan/main.cpp  $(SOURCE_FOLDER)/ProdukHewan/main.cpp ,$(wildcard $(SOURCE_FOLDER)/*/*.cpp $(SOURCE_FOLDER)/*/*/*.cpp ))

compile:
	@echo "Compiling object files..."
	@$(CC) -std=c++17 -o ./bin/Walaoeh ${ALL_SRCS} ./src/main.cpp
	@echo "Compilation done." 

run:
	@./bin/$(EXECUTABLE_FILENAME)

all: compile run

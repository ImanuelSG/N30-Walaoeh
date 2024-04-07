# Compiler & linker
CC            = g++
# Directory
SOURCE_FOLDER = src/libs
OUTPUT_FOLDER = bin

WARNING_CFLAG = -Wall -Wextra -Werror
DEBUG_CFLAG   = -fshort-wchar -g
CFLAGS        = $(DEBUG_CFLAG) $(WARNING_CFLAG)


run: all execute
all: build
build: files
clean:
	rm -rf $(OUTPUT_FOLDER)/*.o $(OUTPUT_FOLDER)/Walaoeh

files: print.o h.o main.o GameWorld.o
	@echo Linking object files
	@$(CC) $(wildcard $(OUTPUT_FOLDER)/*.o) -o $(OUTPUT_FOLDER)/Walaoeh

print.o: ${SOURCE_FOLDER}/Test/print.cpp
	@echo Compiling $<
	@$(CC) $(CFLAGS) -c $< -o $(OUTPUT_FOLDER)/print.o

h.o: ${SOURCE_FOLDER}/compile/h.cpp
	@echo Compiling $<
	@$(CC) $(CFLAGS) -c $< -o $(OUTPUT_FOLDER)/h.o

main.o: src/main.cpp
	@echo Compiling $<
	@$(CC) $(CFLAGS) -c $< -o $(OUTPUT_FOLDER)/main.o

GameWorld.o: src/In-Progress/GameWorld.cpp
	@echo Compiling $<
	@$(CC) $(CFLAGS) -c $< -o $(OUTPUT_FOLDER)/GameWorld.o

execute:
	@./$(OUTPUT_FOLDER)/Walaoeh

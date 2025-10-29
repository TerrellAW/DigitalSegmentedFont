# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -Iinclude

# Output directories
BIN_DIR = bin
OBJ_DIR = build

# Source files
SRC = src/main.c src/font.c src/glyph.c src/writer.c src/utils.c

# Object files
OBJ = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Output binary
BIN = $(BIN_DIR)/digital-segmented-fontgen

# Default target
all: $(BIN)

# Link object files into final binary
$(BIN): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJ) -o $(BIN)

# Compile each C file into an object file
$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts via CLI parameter
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)


# Makefile for PacmanGame

CC = gcc
CFLAGS = -Wall -g

# Directories
SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

# Source files and object files
SRC_FILES = $(wildcard $(SRC_DIR)/**/*.c) $(SRC_DIR)/main.c
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Target executable
TARGET = $(BIN_DIR)/PacmanGame

# Create directories if they do not exist
$(shell mkdir -p $(OBJ_DIR) $(OBJ_DIR)/Ghosts $(OBJ_DIR)/Map $(OBJ_DIR)/Messages $(OBJ_DIR)/Pacman $(OBJ_DIR)/Printer $(BIN_DIR))

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean

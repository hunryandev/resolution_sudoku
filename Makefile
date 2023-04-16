
# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -I./include -c -lm
LFLAGS = -lm

# Executable file name
TARGET = myprogram

# Directories
OBJ_DIR = obj
SRC_DIR = src

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Default target
all: $(TARGET)

# Executable file
$(TARGET): $(OBJS) main.o
	$(CC) $(OBJS) $(LFLAGS) main.o -o $(TARGET)

# Object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS)  $< -o $@

# Main file
main.o: main.c
	$(CC) $(CFLAGS) main.c -o main.o

# Clean up
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET) main.o

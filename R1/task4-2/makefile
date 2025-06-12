# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = main.c other.c
OBJ = main.o other.o
OUT = main.out

# Default target
all: run

# Final executable
$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c to .o
%.o: %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

# Run the program
run: $(OUT)
	./$(OUT)

# Compile only (generates .s)
compile:
	$(CC) -S main.c -o main.s

# Preprocess only (generates .i)
preprocess:
	$(CC) -E main.c -o main.i

# Assemble only
assemble:
	as main.s -o main.o

# Clean
clean:
	rm -f *.o *.out *.i *.s main.i

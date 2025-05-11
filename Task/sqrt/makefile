# Makefile for Python, C, and SystemVerilog builds

# Paths
PYTHON_SRC = python/sqrt_bs.py
C_SRC = C/sqrt_bs.c
SV_SRC = SystemVerilog/sqrt_bs.sv
SV_TB = SystemVerilog/testbench.cpp
BIN_DIR = bin
OBJ_DIR = obj_dir

# Compiler flags
CC = gcc
CFLAGS = -lm
VERILATOR = verilator
VERILATOR_FLAGS = -Wall --cc --trace
VERILATOR_EXE_FLAGS = -exe

# Targets
.PHONY: all clean python c sv

# Default target (all)
all: python c sv

# Python build and run
python: $(PYTHON_SRC)
	clear
	python3 $(PYTHON_SRC)

# C build and run
c: $(C_SRC)
	clear
	rm -f $(BIN_DIR)/sqrt_bs_C
	$(CC) $(C_SRC) -o $(BIN_DIR)/sqrt_bs_C $(CFLAGS)
	$(BIN_DIR)/sqrt_bs_C

# SystemVerilog build and run
sv: $(SV_SRC) $(SV_TB)
	rm -rf $(OBJ_DIR)
	rm -f $(BIN_DIR)/sqrt_bs_sv
	$(VERILATOR) $(VERILATOR_FLAGS) $(SV_SRC) --exe $(SV_TB)
	make -C $(OBJ_DIR) -j -f Vsqrt_bs.mk Vsqrt_bs
	mv $(OBJ_DIR)/Vsqrt_bs $(BIN_DIR)/sqrt_bs_sv
	rm -rf $(OBJ_DIR)
	clear
	$(BIN_DIR)/sqrt_bs_sv

# Clean up intermediate and output files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)/*


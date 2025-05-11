# ==== Variables ====
PYTHON      := python3
PY_SRC      := python/exp.py

C_COMPILER  := gcc
C_SRC       := C/exp_taylor.c
C_OUT       := bin/exp_taylor_C
C_FLAGS     := -lm

SV_SRC      := SystemVerilog/exp_taylor.sv
SV_TB       := SystemVerilog/testbench.cpp
SV_TOP      := Vexp_taylor
SV_OUT      := bin/exp_taylor_sv

VERILATOR   := verilator
VFLAGS      := -Wall --cc --trace

BIN_DIR     := bin
OBJ_DIR     := obj_dir

# ==== Default target ====
.PHONY: all
all: py c sv

# ==== Python ====
.PHONY: py
py:
	@clear
	@echo "Running Python version..."
	@$(PYTHON) $(PY_SRC)

# ==== C ====
.PHONY: c
c:
	@clear
	@echo "Compiling C version..."
	@mkdir -p $(BIN_DIR)
	@$(C_COMPILER) $(C_SRC) -o $(C_OUT) $(C_FLAGS)
	@echo "Running C binary..."
	@./$(C_OUT)

# ==== SystemVerilog ====
.PHONY: sv
sv:
	@echo "Compiling SystemVerilog with Verilator..."
	@rm -rf $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)
	@$(VERILATOR) $(VFLAGS) --exe $(SV_SRC) $(SV_TB)
	@make -C $(OBJ_DIR) -f $(SV_TOP).mk $(SV_TOP)
	@mv $(OBJ_DIR)/$(SV_TOP) $(SV_OUT)
	@rm -rf $(OBJ_DIR)
	@clear
	@echo "Running SystemVerilog binary..."
	@./$(SV_OUT)

# ==== Clean ====
.PHONY: clean
clean:
	@echo "Cleaning build files..."
	@rm -rf $(OBJ_DIR) $(BIN_DIR) $(SV_OUT) $(C_OUT)

# Digital Design and Computer Architecture Summary

## Lecture 1: Introduction & Transistors

### Motivation

* Computers solve problems using layered abstractions: Problem → Algorithm → Program → System Software → Hardware.

### Types of Systems

* **General Purpose**: Flexible but less efficient (e.g., CPUs)
* **Special Purpose**: Efficient but fixed (e.g., GPUs, ASICs)

### MOSFET Basics

* **NMOS**: Conducts when gate = High
* **PMOS**: Conducts when gate = Low
* **Digital Abstraction**: High (3V) = Logic 1, Low (0V) = Logic 0

### CMOS Inverter

* PMOS on top (connected to Vdd), NMOS on bottom (connected to GND)
* Implements NOT gate: Y = NOT A

## Lecture 2: Logic Gates and Boolean Algebra

### Logic Gates & Techniques

* **Bubble Notation**: Bubble = Inversion
* Avoid floating inputs and connecting outputs together
* Use **Tri-State Buffers** for shared buses

### Boolean Algebra

* Operations: AND, OR, NOT
* Laws: Commutative, Associative, Distributive
* **De Morgan’s Laws** and **Duality Principle** essential for simplification

### Function Representation

* Truth Tables, SOP (Sum of Products), POS (Product of Sums)
* Minterms (Σm) and Maxterms (ΠM)

### Key Building Blocks

* **Decoders**: n inputs → 2^n outputs
* **Multiplexers**: 2^n inputs, 1 output
* **Adders**: Half, Full, and Multi-bit Adders
* **PLAs**: Flexible SOP logic implementation

### Minimization Techniques

* Boolean algebra, Karnaugh maps, Quine-McCluskey

## Lecture 3: Sequential Logic Basics

### Combinational vs Sequential Logic

* **Combinational**: Output = f(inputs)
* **Sequential**: Output = f(inputs, previous state)

### Arithmetic Logic Unit (ALU)

* Performs operations (AND, OR, ADD, SUB, etc.) via control signals

### Bus Systems & Tri-State Buffers

* Shared wires require control logic to prevent conflict

### Memory Elements

* **SR Latch**: Stores 1 bit (Set, Reset)
* **D Latch**: Avoids forbidden states, Enable-controlled
* **Flip-Flop**: Edge-triggered (Master-Slave config)

### Registers & Memory

* Registers: Parallel storage of multiple bits
* Memory Arrays: Addressable collections of memory cells
* Memory can implement logic (LUTs, as in FPGAs)

### Finite State Machines (FSMs)

* **States + Transitions** based on input
* Used in locks, traffic controllers, etc.
* Moore (state-driven output) vs Mealy (input-dependent output)

## Lecture 4: FSM Design & FPGA

### Traffic Light FSM

* 4 states: Green A → Yellow A → Green B → Yellow B
* Conditional transitions with timing or sensor input

### FSM Design Methodology

1. Define states
2. Draw transition diagram
3. Assign encoding (Binary, One-Hot, Output)
4. Derive logic equations
5. Implement with flip-flops and logic gates

### Timing Considerations

* Setup, Hold times
* Clock Period must accommodate logic delays

### FPGA Introduction

* Configurable logic (LUTs), routing fabric
* Advantage: Reprogrammable, high parallelism
* Common in bioinformatics, AI, security research

### Verilog Basics

* Module structure: inputs/outputs, logic inside
* Hierarchical design: Top-down + Bottom-up
* HDL required due to scale of modern designs

## Lecture 5: Verilog Advanced & Timing

### Verilog Essentials

* **Bit Vectors**, **Arrays**, **Reduction Operators**
* Conditional (`? :`) and case statements

### Sequential Logic in Verilog

* `always @(posedge clk)` for flip-flops
* Use `<=` for non-blocking assignments

### FSM in Verilog

* Three-block model: State Register, Next-State Logic, Output Logic
* Always define reset state

### Timing Verification

* Delays: Propagation, Contamination
* Constraints: Setup/Hold Time, Clock Frequency

### Best Practices

* Clear hierarchy, complete case handling, no clock creation in logic
* Avoid mixed assignment types in always blocks

## Lecture 6: Timing & Verification II

### Circuit Timing Fundamentals

* Real circuits have delays due to physical factors (resistance, capacitance, temperature)

#### Delays

* **Contamination Delay (tcd)**: Earliest signal can change
* **Propagation Delay (tpd)**: Latest output stabilizes

#### Flip-Flop Timing

* **Setup Time**: Data must be stable before clock edge
* **Hold Time**: Data must stay stable after clock edge
* **Clock-to-Q Delay**: Time from clock edge to output change
* Violations lead to metastability

#### Clock Skew

* Differences in clock arrival times affect setup/hold constraints
* Needs careful design

### Circuit Optimization

* Identify and shorten **critical paths**
* Use **pipelining**, balance delays, and choose optimal technology

### Verification Methods

* **Testbenches**: Manual, file-based, or self-checking
* **Formal Verification**: Mathematical correctness (SAT, model checking)

#### Simulation & Tools

* **Static Timing Analysis (STA)**: Analyzes paths without simulation
* **Logic Synthesis**: Convert HDL to gates
* **Place & Route**: Translate to physical layout

### Clock Domain Crossing

* **Synchronizers** and **handshaking** needed to prevent metastability

### Process Variation

* Design must account for variations in manufacturing
* Worst-case margins and statistical analysis essential

### Key Principles

1. Start with timing in mind
2. Conservative analysis
3. Balance delays
4. Comprehensive verification
5. Understand EDA tool limitations
6. Iterative refinement
7. Maintain good documentation

### Common Pitfalls

* Ignoring hold time or clock skew
* Insufficient test coverage
* Timing closure left too late
* Designing only for typical conditions

---

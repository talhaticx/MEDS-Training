#include "Vadder.h"
#include "verilated.h"

int main(int argc, char** argv) {
    // Initialize Verilator
    Verilated::commandArgs(argc, argv);

    // Create a new instance of the adder
    Vadder* top = new Vadder;

    // Apply test vectors (example inputs)
    top->A = 0b1010;  // Correct binary format in C++
    top->B = 0b0111;
    top->Cin = 0;  // Example carry-in

    // Evaluate the design (run the simulation)
    top->eval();

    // Check results (you might need to print or compare outputs)
    printf("Sum: %b, Cout: %b\n", top->Sum, top->Cout);

    // Clean up
    delete top;
    return 0;
}

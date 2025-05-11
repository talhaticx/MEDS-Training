#include <verilated.h>
#include "Vsqrt_bs.h"
#include <iostream>
#include <cmath>

#define Q24_8_TO_FLOAT(x)   ((float)(x) / 256.0f)   // Q24.8 -> Float
#define FLOAT_TO_Q24_8(x)   ((uint32_t)((x) * 256.0f)) // Float -> Q24.8

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vsqrt_bs* top = new Vsqrt_bs;

    // Test values for square root calculation
    for (float i = 1.0f; i <= 25.0f; i++) {
        // Convert float input to Q24.8 fixed point format
        float test_input_float = i;
        uint32_t test_input_q24_8 = FLOAT_TO_Q24_8(test_input_float);

        // Apply the input to the DUT (Device Under Test)
        top->x = test_input_q24_8;

        // Evaluate the design
        top->eval();

        // Convert the FPGA output from Q24.8 fixed-point to float
        float output_float = Q24_8_TO_FLOAT(top->root);

        // Print the results
        std::cout << "Input (x): " << test_input_float << std::endl;
        std::cout << "Expected sqrt(x): " << sqrt(test_input_float) << std::endl;
        std::cout << "FPGA Output (Q24.8): " << output_float << std::endl;
        std::cout << "\n" << std::endl;
    }

    // Clean up and exit
    delete top;
    return 0;
}

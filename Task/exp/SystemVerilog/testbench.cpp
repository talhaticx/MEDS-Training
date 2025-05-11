#include <verilated.h>
#include "Vexp_taylor.h"
#include <iostream>
#include <cmath>

#define Q16_16_TO_FLOAT(x)   ((float)(x) / 65536.0f)
#define FLOAT_TO_Q16_16(x)   ((uint32_t)((x) * 65536.0f))

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vexp_taylor* top = new Vexp_taylor;
    for (float i = 0; i < 5; i=i+0.5){

        float test_input = i;
        top->x = FLOAT_TO_Q16_16(test_input);
    
        top->eval();
    
        float output = Q16_16_TO_FLOAT(top->y);

        std::cout << "Input (x): " << test_input << std::endl;
        std::cout << "Expected (e^x): " << exp(test_input) << std::endl;
        std::cout << "FPGA Output (Q16.16): " << output << std::endl;
        std::cout << "\n" << std::endl;
    }

    delete top;
    return 0;
}

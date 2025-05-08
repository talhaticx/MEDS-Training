module Adder (
    input logic [3:0] A,    // 4-bit input A
    input logic [3:0] B,    // 4-bit input B
    input logic Cin,        // Carry input
    output logic [3:0] Sum, // 4-bit sum
    output logic Cout       // Carry output
);

    assign {Cout, Sum} = A + B + Cin; // Simple addition with carry propagation

endmodule

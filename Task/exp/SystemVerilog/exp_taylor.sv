function automatic logic [31:0] fx_mult(input logic [31:0] a, b);
    /* verilator lint_off UNUSEDSIGNAL */
    logic [63:0] temp;
    /* verilator lint_on UNUSEDSIGNAL */
    begin
        temp = a * b;              // Q16.16 * Q16.16 = Q32.32
        fx_mult = temp[47:16];     // Truncate to Q16.16
    end
endfunction

function automatic logic [31:0] fx_div(input logic [31:0] a, b);
    logic [63:0] temp_a;
    /* verilator lint_off UNUSEDSIGNAL */
    logic [63:0] temp;
    /* verilator lint_on UNUSEDSIGNAL */
    begin
        temp_a = {32'd0, a};                       // Extend a to 64 bits
        temp   = (temp_a << 16) / {32'd0, b};      // Extend b to 64 bits before division
        fx_div = temp[31:0];                       // Truncate to Q16.16
    end
endfunction


function automatic logic [31:0] factorial(input int i);
    begin
        case (i)
            0: factorial = 32'd65536;        // 1
            1: factorial = 32'd65536;        // 1
            2: factorial = 32'd131072;       // 2
            3: factorial = 32'd393216;       // 6
            4: factorial = 32'd1572864;      // 24
            5: factorial = 32'd7864320;      // 120
            6: factorial = 32'd47185920;     // 720
            7: factorial = 32'd331776000;    // 5040
            default: factorial = 32'd1;
        endcase
    end
endfunction

module exp_taylor(
    input  logic [31:0] x,  // Q16.16 input
    output logic [31:0] y   // Q16.16 output
);
    logic [31:0] term, power;
    logic [31:0] sum;
    int i;

    always_comb begin
        sum   = 32'd65536; // 1.0 in Q16.16
        power = 32'd65536; // x^0 = 1.0
        for (i = 1; i <= 7; i++) begin
            power = fx_mult(power, x);              // x^i
            term  = fx_div(power, factorial(i));    // x^i / i!
            sum   = sum + term;
        end
        y = sum;
    end
endmodule

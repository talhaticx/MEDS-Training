module sqrt_bs (
    input  logic [31:0] x,    // Input in Q24.8
    output logic [31:0] root  // Output in Q24.8
);
    logic [31:0] low, high, mid, mid_sq;
    int i;

    // Fixed-point multiplication for Q24.8: result = (a * b) >> 8
    function automatic logic [31:0] fx_mult(input logic [31:0] a, b);
    /* verilator lint_off UNUSEDSIGNAL */
    logic [63:0] temp;
    /* verilator lint_on UNUSEDSIGNAL */
        begin
            temp = a * b;            // Q24.8 * Q24.8 = Q48.16
            fx_mult = temp[39:8];    // Truncate to Q24.8
        end
    endfunction

    always_comb begin
        low  = 32'd0;
        high = x;
        for (i = 0; i < 32; i++) begin
            mid = (low + high) >> 1;
            mid_sq = fx_mult(mid, mid);
            if (mid_sq == x)
                break;
            else if (mid_sq < x)
                low = mid;
            else
                high = mid;
        end
        root = mid;
    end
endmodule

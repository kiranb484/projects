`include "full_adder.v"

module ripple_adder ( output [3:0] S,
                      output C_out,
                      input [3:0] A,
                      input [3:0] B,
                      input C_in);

    wire C1, C2, C3;

    full_adder FA0 (S[0], C1, A[0], B[0], C_in);
    full_adder FA1 (S[1], C2, A[1], B[1], C1);
    full_adder FA2 (S[2], C3, A[2], B[2], C2);
    full_adder FA3 (S[3], C_out, A[3], B[3], C3);
endmodule
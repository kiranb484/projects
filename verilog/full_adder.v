`include "sum_carry.v"

module full_adder ( output S,
                    output C_out,
                    input A,
                    input B,
                    input C_in);
    sum SUM (S, A, B, C_in);
    carry CARRY (C_out, A, B, C_in);

endmodule
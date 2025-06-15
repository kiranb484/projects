// `include "sum_carry.v"
`include "full_adder.v"

module test_bench;
    reg A, B, C_in; wire S, C_out;
    full_adder DUT (S, C_out, A, B, C_in);

    initial
        begin
            $dumpfile("full_adder.vcd");
            $dumpvars(0, DUT);
            $monitor($time, " A=%b B=%b C_in=%b S=%b C_out=%b", A, B, C_in, S, C_out);

            // Test cases
            #5 A = 0; B = 0; C_in = 0; // S = 0, C_out = 0
            #5 A = 0; B = 0; C_in = 1; // S = 1, C_out = 0
            #5 A = 0; B = 1; C_in = 0; // S = 1, C_out = 0
            #5 A = 0; B = 1; C_in = 1; // S = 0, C_out = 1
            #5 A = 1; B = 0; C_in = 0; // S = 1, C_out = 0
            #5 A = 1; B = 0; C_in = 1; // S = 0, C_out = 1
            #5 A = 1; B = 1; C_in = 0; // S = 0, C_out = 1
            #5 A = 1; B = 1; C_in = 1; // S = 1, C_out = 1
            #5 A = 0; B = 0; C_in = 0; // S = 0, C_out = 0

            $display("Test complete");

        end

endmodule
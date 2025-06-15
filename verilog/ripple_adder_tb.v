`include "ripple_adder.v"

module ripple_adder_tb;
    reg [3:0] A;
    reg [3:0] B;
    reg c_in; wire [3:0] S; wire C_out;
    ripple_adder DUT (S, C_out, A, B, c_in);

    initial
        begin
            $dumpfile("ripple_adder.vcd");
            $dumpvars(0, DUT);
            $monitor($time, " A=%b B=%b C_in=%b S=%b C_out=%b", A, B, c_in, S, C_out);

            // Test cases
            #5 A = 4'b0000; B = 4'b0000; c_in = 1'b0; // S = 0000, C_out = 0
            #5 A = 4'b0001; B = 4'b0001; c_in = 1'b0; // S = 0010, C_out = 0
            #5 A = 4'b0010; B = 4'b0011; c_in = 1'b0; // S = 0101, C_out = 0
            #5 A = 4'b0111; B = 4'b0111; c_in = 1'b0; // S = 1110, C_out = 0
            #5 A = 4'b1111; B = 4'b1111; c_in = 1'b0; // S = 1110, C_out = 1
            #5 A = 4'b1010; B = 4'b0101; c_in = 1'b1; // S = 0000, C_out = 1

            $display("Test complete");
        end


endmodule
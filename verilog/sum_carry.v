module sum (S, A, B, C_in);
    input A, B, C_in;
    output S;
    wire t;

    xor x1 (t, A, B);
    xor x2 (S, t, C_in);
endmodule

module carry (C_out, A, B, C_in);
    input A, B, C_in;
    output C_out;
    wire t1, t2, t3;

    and a1 (t1, A, B);
    and a2 (t2, B, C_in);
    and a3 (t3, A, C_in);
    or o (C_out, t1, t2, t3);

endmodule
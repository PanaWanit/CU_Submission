`timescale 1ns / 1ps

module InputBuffer(
    input wire P,
    input wire clock,
    output reg Z
    );
    wire s0,s1,s2;
    DFF u0(P, clock, s0);
    DFF u1(s0, clock, s1);
    Deboucer u2(s1, clock, s2);
    Single_Pulser u3(s2, clock, Z);


endmodule
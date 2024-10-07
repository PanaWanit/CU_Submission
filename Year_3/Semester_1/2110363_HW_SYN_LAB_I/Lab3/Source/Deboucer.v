`timescale 1ns / 1ps
module Deboucer(
    input wire P,
    input wire clock,
    output reg Z
    );
    reg [20:0] count;
    always @(posedge clock) begin
        count <= count + 1;
        if(count == 0) begin
            Z <= P;
        end
    end
endmodule
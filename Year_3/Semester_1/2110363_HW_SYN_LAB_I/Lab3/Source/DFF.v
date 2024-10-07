`timescale 1ns / 1ps

module DFF(
    input wire P,
    input wire clock,
    output reg Z
    );

    always @(posedge clock) begin
        Z <= P;
    end

endmodule
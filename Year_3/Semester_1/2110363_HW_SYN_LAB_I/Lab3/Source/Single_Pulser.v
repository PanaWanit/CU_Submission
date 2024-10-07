`timescale 1ns / 1ps

module Single_Pulser(
    input wire P,
    input wire clock,
    output wire Z
    );
    reg tmp;
    always @(posedge clock) begin
        tmp <= P;
        Z <= (!tmp && P);
    end

endmodule
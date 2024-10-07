`timescale 1ns / 1ps

module Single_Pulser(
    input wire P,
    input wire clock,
    output reg Z
    );
    reg tmp;

    tmp <= P;
    Z <= (!tmp && P);

endmodule
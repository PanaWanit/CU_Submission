`timescale 1ns / 1ps

module BCD (
    input wire up,down,set,reset,
    input wire clock,
    output reg [3:0] A,
    output wire carry, borrow
    );

    // async
    assign carry = (A == 9 && up);
    assign borrow = (A == 0 && down);

    always @(posedge clock) begin
        if(up) begin
            if(A == 9) 
                A <= 0;
            else 
                A <= A + 1;
        end
        else if(down) begin
            if(A == 0) 
                A <= 9;
            else 
                A <= A - 1;
        end
        else if(set) 
            A <= 9;
        else if(reset)
            A <= 0;
    end
    
endmodule
`timescale 1ns/1ps
module SevenSegment(
    input wire [3:0] A,B,C,D,
    input wire clock,
    output wire [6:0] Ca,
    output reg [3:0] An
    );

    reg [3:0] cur;
    reg [19:0] cnt;
    Encoder u0(cur, Ca);
    always @(posedge clock) begin
        cnt <= cnt+1;
        case (cnt[19:18])
            2'b00 : begin An <= 4'b1110; cur <= A; end
            2'b01 : begin An <= 4'b1101; cur <= B; end
            2'b10 : begin An <= 4'b1011; cur <= C; end
            2'b11 : begin An <= 4'b0111; cur <= D; end
        endcase
    end
endmodule
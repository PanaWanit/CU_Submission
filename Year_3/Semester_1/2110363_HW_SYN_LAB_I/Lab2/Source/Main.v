`timescale 1ns / 1ps

module Main(
    output wire [6:0] C_LED,
    output reg [3:0] A_LED,
    input wire clock
);

reg [15:0] inp = 16'h1234;
reg [3:0] cur = 4'b1111;
reg [19:0] cnt;

Encoder u1(cur, C_LED);
always @(posedge clock) begin
    case (cnt[19:18])
        'd0: begin A_LED <= 4'b1110; cur <= inp[3:0]  ; end
        'd1: begin A_LED <= 4'b1101; cur <= inp[7:4]  ; end
        'd2: begin A_LED <= 4'b1011; cur <= inp[11:8] ; end
        'd3: begin A_LED <= 4'b0111; cur <= inp[15:12]; end
    endcase
    cnt <= cnt + 1;
end



endmodule